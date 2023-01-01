#!/bin/bash
set -e

# A bash script for building the repository

colcon build
. install/setup.bash