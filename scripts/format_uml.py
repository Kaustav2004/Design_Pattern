import html
import re
import sys
from pathlib import Path


CLASS_DECLARATION = re.compile(r'^\s*class\s+(\w+)\["([^"]+)"\]\s*$')
CLASS_BODY = re.compile(r"^\s*class\s+(\w+)\s*\{\s*$")
METHOD = re.compile(
    r"^\s*([+#~-])([A-Za-z_]\w*)\((.*?)\)\s+(?:\[const\]\s+)?(.+?)\s*$"
)
RELATION = re.compile(r"^\s*(\w+)\s+(<\|--|\.\.>)\s+(\w+)\s*:")


def simplify_type(type_name):
    type_name = html.unescape(type_name).strip()
    type_name = re.sub(r"\bconst\s+", "", type_name)
    type_name = type_name.replace("&", "").replace("*", "").strip()
    type_name = re.sub(r"^std::", "", type_name)
    if type_name.startswith("unique_ptr<") and type_name.endswith(">"):
        type_name = type_name[len("unique_ptr<") : -1]
    return type_name


def simplify_arguments(arguments):
    if not arguments.strip():
        return ""
    result = []
    for argument in arguments.split(","):
        parts = argument.strip().rsplit(None, 1)
        if len(parts) == 1:
            result.append(simplify_type(parts[0]))
        else:
            result.append(f"{parts[1]}: {simplify_type(parts[0])}")
    return ", ".join(result)


def format_diagram(path):
    lines = path.read_text().splitlines()
    classes = {}
    operations = {}
    raw_relations = []

    for line in lines:
        declaration = CLASS_DECLARATION.match(line)
        if declaration:
            identifier, name = declaration.groups()
            name = html.unescape(name)
            if name.startswith("std::") or name.startswith("std::unique_ptr"):
                continue
            classes[identifier] = name
            operations[identifier] = {"abstract": False, "methods": []}
            continue

        relation = RELATION.match(line)
        if relation:
            source, kind, target = relation.groups()
            raw_relations.append((source, kind, target))

    current_class = None
    for line in lines:
        body = CLASS_BODY.match(line)
        if body:
            current_class = body.group(1) if body.group(1) in classes else None
            continue
        if current_class is None:
            if line.strip() == "}":
                current_class = None
            continue
        if line.strip() == "}":
            current_class = None
            continue
        content = line.strip()
        if content == "<<abstract>>":
            operations[current_class]["abstract"] = True
            continue
        method = METHOD.match(line)
        if not method:
            continue
        visibility, name, arguments, return_type = method.groups()
        if name.startswith("~") or name == classes[current_class]:
            continue
        parameters = simplify_arguments(arguments)
        signature = f"{visibility}{name}({parameters})"
        operations[current_class]["methods"].append(signature)

    if not classes:
        raise ValueError(f"No project classes found in {path}")

    rendered = ["classDiagram", "    direction LR"]
    for identifier, name in classes.items():
        details = operations[identifier]
        rendered.append(f"    class {name} {{")
        if details["abstract"]:
            rendered.append("        <<abstract>>")
        rendered.extend(f"        {method}" for method in details["methods"])
        rendered.append("    }")

    relations = set()
    for source, kind, target in raw_relations:
        if source not in classes or target not in classes:
            continue
        if kind == "<|--":
            relations.add((classes[source], kind, classes[target], "implements"))

    project_names = set(classes.values())
    for factory in project_names:
        if not factory.endswith("Factory"):
            continue
        product = factory[: -len("Factory")]
        if product in project_names:
            relations.add((factory, "..>", product, "creates"))

    for source, kind, target, label in sorted(relations):
        rendered.append(f"    {source} {kind} {target} : {label}")

    path.write_text("\n".join(rendered) + "\n")


if __name__ == "__main__":
    for filename in sys.argv[1:]:
        format_diagram(Path(filename))
