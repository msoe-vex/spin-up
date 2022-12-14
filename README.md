# spin-up
Raider Robotics repository for VEXU Spin Up.

### Setup
This repository is setup as a visual studio code dev container. To work on code:
1. Install [Docker Desktop](https://www.docker.com/products/docker-desktop/).
2. Install [VS Code](https://code.visualstudio.com/). Note this is different from Visual Studio, which is purple, not blue.
3. Add the Dev Containers extension.
4. Open the command pallette using *Ctrl + Shift + P*, then search for *Dev Containers: Open Folder in Container* and select the folder containing a local copy of this repository.

### Commands
* Use VS Code's **Run and Debug** menu (*Ctrl + Shift + D*) to compile and run programs in debugging mode.
* Run `make` to compile everything.
* Run `make example` to compile *publisher_example*.
* Run `make run-example` to run *publisher_example*.
* Run `make clean` or `make purge` to cleanup generated files.

### Maintenance
* Programs which can be run should have corresponding tasks defined in `launch.json`, `tasks.json`, and `Makefile`.
* Packages are defined in `Dockerfile`. 
* VSCode extensions are defined in `devcontainer.json`.