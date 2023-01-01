#!/bin/bash
set -e

rosdep update
rosdep install --from-paths src -y