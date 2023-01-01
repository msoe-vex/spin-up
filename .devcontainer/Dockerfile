# We'll start with althack's dev enviornment
FROM althack/ros2:foxy-dev

# Set up auto-source of workspace for ros user
# ARG WORKSPACE
# RUN echo "if [ -f ${WORKSPACE}/install/setup.bash ]; then source ${WORKSPACE}/install/setup.bash; fi" >> /home/ros/.bashrc
ARG WORKSPACE
RUN echo "source ${WORKSPACE}/install/setup.bash" >> ~/.bashrc

# RUN ${WORKSPACE}/scripts/setup.sh