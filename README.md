## IsingGraph

This library aims to provide a generic framework for simulating nearest-neighbour Ising-type spin models with fully configurable model, algorithm and graph structure.

The Ising model is an important and well-studied model of ferromagnetism, due to its rich behaviour (it can exhibit phase transitions) and the existence of an exact analytical solution for the model on a two-dimensional square lattice. Although it most widely studied on regular lattices, Ising networks with more complex architecture have been shown to display unique effects of their own. Models on scale-free networks, random networks, trees, and many others each show distinct and interesting behaviours.

There are several generalisations of the Ising model, such as the Potts model and O(n) vector models, and several different algorithms with which to simulate them. This library provides a way to efficiently and easily study different combinations of these factors, with as small as possible runtime overhead through the use of C++ template techniques.

Programmable weights between spins and exteranl magnetic fields are not currently supported, but there is interest in integrating these features if possible.

The project structure comes from this Meson sample project: https://github.com/tiernemi/meson-sample-project

### Building The Project

The project build directory is created using the following command.
```bash
meson build
```

Builds can be triggered using ninja once inside this build directory.
```bash
ninja
```

### Running Tests

Benchmarks require an installed [googletest](https://github.com/google/googletest)
Tests are created using googletest and can be run using ninja once inside the build directory.

```bash
ninja test
```

To run tests with address santization, build meson with this command.

```
meson build -Db_sanitize=address
cd build
ninja
ninja test
```

### Wrapping Tests With Valgrind

Meson has the ability to wrap the tests in valgrind. This is useful for spotting easily avoidable memory leaks. From within the build directory run

```bash
meson test --wrap='valgrind --tool=helgrind' testname
```

### Wrapping Tests With GDB

Meson has the ability to wrap the tests in gdb. This is useful for debugging. From within the build directory run

```bash
meson test --gdb testname
```

### Running Benchmarks

Benchmarks require an installed [benchmark](https://github.com/google/benchmark)
Benchmarks are created using google's benchmark library and can be run using ninja once inside the build directory.

```bash
ninja benchmark
```

### Formatting

To format you simply run the following command in the build directory.

```bash
ninja format
```

### Tidying

There is a linter integrated into this project which enforces various style choices. This will automatically fix your code to align with these standards. It will also display issues that can't be autofixed.

```bash
ninja tidy
```

### Creating Documentation

Documentation generation requires [doxygen](https://github.com/doxygen/doxygen)
Documentation is created using doxygen. These can be generated using ninja once inside the build directory.

```bash
ninja doc
```

### Creating Coverage Reports

Coverage reports require gcov.
The build directory can be configured to generate coverage as follows.

```bash
 meson build_coverage <other flags> -Db_coverage=true
```
Coverage can then be generated as follows.

```bash
ninja
ninja test
ninja coverage-html
```
### Running Static Analysis

Static analysis requires clang.
Running static analysis is as simple as running the following command from the build directory.

```bash
ninja scan-build
```
