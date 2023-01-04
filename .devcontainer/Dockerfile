# FROM althack/ros2:foxy-dev
FROM althack/ros2:humble-dev

ARG WORKSPACE
RUN apt-get update && apt-get install \
    -y --no-install-recommends \
    ros-humble-hardware-interface \
    ros-humble-controller-manager \
    && apt-get autoremove -y

# Set up source of workspace for ros user
RUN echo "source ${WORKSPACE}/install/setup.bash" >> ~/.bashrc
# Alternative which puts a conditional in ./bashrc:
# RUN echo "if [ -f ${WORKSPACE}/install/setup.bash ]; then source ${WORKSPACE}/install/setup.bash; fi" >> /home/ros/.bashrc