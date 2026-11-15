import re
import sys
import xml.etree.ElementTree as ET
from pathlib import Path


SVG_NAMESPACE = "http://www.w3.org/2000/svg"
ET.register_namespace("", SVG_NAMESPACE)
ET.register_namespace("xlink", "http://www.w3.org/1999/xlink")


def add_legend(path):
    tree = ET.parse(path)
    root = tree.getroot()
    if root.find(f"{{{SVG_NAMESPACE}}}g[@id='uml-legend']") is not None:
        raise ValueError(f"{path} already contains a UML legend")

    min_x, min_y, width, height = map(float, root.attrib["viewBox"].split())
    legend_height = 76
    root.set("viewBox", f"{min_x} {min_y} {width} {height + legend_height}")
    root.set("width", f"{width}px")
    root.set("height", f"{height + legend_height}px")
    style = re.sub(r"max-width:\s*[^;]+;?", "", root.get("style", ""))
    root.set("style", f"{style};max-width:100%;height:auto;")

    legend = ET.SubElement(
        root,
        f"{{{SVG_NAMESPACE}}}g",
        {"id": "uml-legend", "font-family": "Arial, sans-serif", "font-size": "16"},
    )
    top = min_y + height
    ET.SubElement(
        legend,
        f"{{{SVG_NAMESPACE}}}rect",
        {
            "x": str(min_x),
            "y": str(top),
            "width": str(width),
            "height": str(legend_height),
            "fill": "#ffffff",
            "stroke": "#cccccc",
        },
    )

    def line(x1, x2, y, dashed=False, triangle=False):
        tip = x2 - 12 if triangle else x2 - 10
        attrs = {
            "x1": str(x1),
            "y1": str(y),
            "x2": str(tip),
            "y2": str(y),
            "stroke": "#333333",
            "stroke-width": "2",
        }
        if dashed:
            attrs["stroke-dasharray"] = "5 4"
        ET.SubElement(legend, f"{{{SVG_NAMESPACE}}}line", attrs)
        ET.SubElement(
            legend,
            f"{{{SVG_NAMESPACE}}}path",
            {
                "d": (
                    f"M {x2 - 12} {y - 8} L {x2} {y} L {x2 - 12} {y + 8} Z"
                    if triangle
                    else f"M {x2 - 10} {y - 6} L {x2} {y} L {x2 - 10} {y + 6}"
                ),
                "fill": "#ffffff" if triangle else "none",
                "stroke": "#333333",
                "stroke-width": "2",
            },
        )

    def label(x, text):
        text_element = ET.SubElement(
            legend,
            f"{{{SVG_NAMESPACE}}}text",
            {"x": str(x), "y": str(top + 47), "fill": "#222222"},
        )
        text_element.text = text

    row_y = top + 39
    left = min_x + 24
    line(left, left + 66, row_y, triangle=True)
    label(left + 82, "Inheritance (triangle points to parent)")

    right = min_x + width * 0.53
    line(right, right + 66, row_y, dashed=True)
    label(right + 82, "Creates (dashed dependency)")

    tree.write(path, encoding="utf-8", xml_declaration=True)


if __name__ == "__main__":
    for filename in sys.argv[1:]:
        add_legend(Path(filename))
