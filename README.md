# Design Patterns

This repository contains C++ factory-pattern examples. Class diagrams are
generated from the source with [clang-uml](https://github.com/bkryza/clang-uml)
and saved in [`docs/diagrams`](docs/diagrams).

## Generate diagrams locally

Install `clang-uml`, CMake, and a C++ compiler, then run:

```sh
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
clang-uml --progress --query-driver /usr/bin/c++
```

GitHub Actions regenerates and commits the PlantUML diagrams when C++ source or
diagram configuration changes are pushed to `main`. You can also run the
workflow manually from the repository's **Actions** tab.
