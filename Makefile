#!/usr/bin/make -f
SHELL = /bin/sh

# Usage: 
# make (or: make all)
# make test
# make clean
# make purge
# etc.

all: 
	colcon build --packages-skip spin_up

example:
	colcon build --packages-select publisher_example

test:
	source install/setup.bash
	colcon test
	colcon test-result

clean:
	colcon build --cmake-target clean

purge:
	rm -fr build install log

setup:
	rosdep update
	rosdep install --from-paths src -y