#!/usr/bin/make -f
SHELL = /bin/sh

# Usage: 
# make (or: make all)
# make test
# make clean
# make purge
# etc.

all: 
	colcon build

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