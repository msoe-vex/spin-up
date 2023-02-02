# spin-up design

## Style
This code loosely follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Some notable exceptions are as follows:
1. A few custom formatting rules are defined and automatically configured by the compiler. Use VS Code's autoformater (default: `Crtl+Shift+F`) to format files.
2. `#pragma once` may be used in header files over `include` guards.

# Organization
Each file should have a namespace; even classes. Namespaces should be organized by folder; e.g. everything in the `hardware` folder should have the `hardware` namespace.

Robot code should interact exclusively with virtual classes defined in `interface`. `hardware` implementations should implement a respective `interface` in order to provide a consistent and swap-able API.