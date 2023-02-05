# spin-up design

## Style
This code loosely follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Some notable exceptions are as follows:
1. A few custom formatting rules are defined and automatically configured by the compiler. Use VS Code's autoformater (default: *Ctrl + Shift + F*) to format files.
2. `#pragma once` may be used in header files over `include` guards.
3. `src` files are named using `.cpp` instead of `.cc`.

# Organization
Each file should have a namespace; even classes. Namespaces should be organized by folder; e.g. everything in the `hardware` folder should have the `hardware` namespace.

Robot code should interact exclusively with virtual classes defined in `interface`. `hardware` implementations should implement a respective `interface` in order to provide a consistent and swapable API.

Interfaces are instantiated in factory functions which may be attached to their respective `hardware` (e.g. `pros_controller`) or in the respective subsystem (e.g. `holonomic_drive`). Factory functions should be configured with data from `constant`. Note factories should return `std::unqiue_ptr<interface::<InterfaceClass>` in order to enable virtualization.