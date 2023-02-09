# spin-up design

## Style
This code loosely follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Some notable exceptions are as follows:
1. A few custom formatting rules are defined and automatically configured by the compiler. Use VS Code's autoformater (default: *Ctrl + Shift + F*) to format files.
2. `#pragma once` may be used in header files over `include` guards.
3. `src` files are named using `.cpp` instead of `.cc`.
4. Exceptions are allowed to be used to demark states which are clearly illegal and should never be reached.

# Organization
Each file should have a namespace; even classes. Namespaces should be organized by folder; e.g. everything in the `hardware` folder should have the `hardware` namespace.

Robot code should interact exclusively with virtual classes defined in `interface`. `hardware` implementations should implement a respective `interface` in order to provide a consistent and swapable API.

The [Purdue Robot Operating System](https://pros.cs.purdue.edu/v5/index.html#) (pros) is available via the include `#include "pros.h"`.

Interfaces are instantiated in factory functions which may be attached to their respective `hardware` (e.g. `pros_controller`) or in the respective subsystem (e.g. `holonomic_drive`). Factory functions should be configured with data from `constant`. Note factories should return `std::unique_ptr<interface::<InterfaceClass>` in order to enable virtualization.

Methods and functions which behave like simple getters (e..g encoder `velocity`) should be written as standard variables. Functions which do more computation or which do not expose (or pretend to expose) a field on a class should be written as `Get<MyValue>`, e.g. `GetProsJoystick`.