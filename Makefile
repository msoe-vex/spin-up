#!/usr/bin/make -f
SHELL = /bin/sh

# v5_hal is built by diffdrive_arduino?
all: 
	colcon build

example:
	colcon build --packages-select publisher_example

run-example:
	ros2 run publisher_example publisher

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
	rosdep install -y --from-paths src