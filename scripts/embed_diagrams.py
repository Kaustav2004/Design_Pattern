from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"
DIAGRAMS = ("notification_factory", "payment_factory")


def main():
    readme = README.read_text()

    for name in DIAGRAMS:
        start = f"<!-- UML:{name}:start -->"
        end = f"<!-- UML:{name}:end -->"
        if readme.count(start) != 1 or readme.count(end) != 1:
            raise ValueError(f"README must contain exactly one marker pair for {name}")

        start_index = readme.index(start) + len(start)
        end_index = readme.index(end)
        if start_index > end_index:
            raise ValueError(f"README markers are out of order for {name}")

        diagram_path = ROOT / "docs" / "diagrams" / f"{name}.mmd"
        diagram = diagram_path.read_text().strip()
        replacement = f"\n\n```mermaid\n{diagram}\n```\n"
        readme = readme[:start_index] + replacement + readme[end_index:]

    README.write_text(readme)


if __name__ == "__main__":
    main()
