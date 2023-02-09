# spin-up design

## Style
This code loosely follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Some notable exceptions are as follows:
1. A few custom formatting rules are defined and automatically configured by the compiler. Use VS Code's autoformater (default: *Ctrl + Shift + F*) to format files.
2. `#pragma once` may be used in header files over `include` guards.
3. `src` files are named using `.cpp` instead of `.cc`.
4. Exceptions are allowed to be used to demark states which are clearly illegal and should never be reached.

# Organization
Each file should have a namespace; even classes. Namespaces should be organized by folder; e.g. everything in the `hardware` folder should have the `hardware` namespace. Nested namespaces may be used if additional granularity is necessary, but this use case should be rare.

The [Purdue Robot Operating System](https://pros.cs.purdue.edu/v5/index.html#) (pros) is available via the header `#include "pros.h"`. In general, `pros` code should be wrapped into generic implementations in `hardware`; thus, it shouldn't be necessary to import `pros` outside of that folder.

# Code Flow and Constructs
Virtual interfaces are used to create an abstraction layer between use cases on the robot and physical hardware. Interfaces are defined in `interface` and describe a minimal set of methods necessary for using/interacting with an object. Since these `interface`s are generic, any class which fulfills their basic requirements may be substituted as the concrete implementation. 

Factory methods should be `static` methods belonging to either a concrete implementation or a subsystem. Their name should be `Make`, e.g. `MakeDriverController`. They should return one or more `std::unique_ptr`s which are set to the concrete implementation rather than the underlying interface (e.g. `ProsController`, not `interface::Controller`). This enables useage of additional, non-interface methods in `main` and supports classes which implement more than one interface (like `ProsMotor`).

In contrast, subsystems should interact with `interface`s only (and not concrete implementations). For example, a drivetrain should receive `interface::Motor`s and an `interface::Controller` rather than, say, `ProsMotor` and `ProsController`. This enables these implementations to be freely swapped. Generally, users should only take references to specific `interface`s needed since taking the entire `std::unique_ptr` takes ownership of that object. For example, `HolonomicDrivetrain` may receive a controller to work with using the signature `Drive(const interface::Controller& controller) {}`. This method should be called by dereferencing the `std::unique_ptr<ProsController>` pointer managed by main, e.g. `drivetrain.Drive(*controller_ptr);`. 

Classes which take ownership over one or more concrete implementations, such as `HolonomicMotors`, by taking one or more `std::unique_ptr`s as members, should have its copy constructor and operator deleted and the rest of its constructors defined (in order to properly observe the rule of 5). As a reminder, classes which own `std::unique_ptr` cannot be copied, only moved; this can be accomplished with `std::move`. To facilitate error checking and prevent hard to detect bugs, the copy constructor and copy assignment operator should be deleted, and the other constructors/destructors (move constructor, move assignment, destructor) should be specified/assigned to `default` . See `holonomic_motors.h` for an example.

Methods (but not functions) which behave like simple getters (e.g. encoder's `velocity`) should be written as standard variables (as opposed to `Velocity` or `GetVelocity`). Non-method functions which do more computation or which do not expose (or pretend to expose) a field on a class should be written as `Get<MyValue>`, e.g. `GetProsJoystick`.