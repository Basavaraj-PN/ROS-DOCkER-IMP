FROM osrf/ros:melodic-desktop

ARG CATKIN_WS=/catkin_ws
ENV CATKIN_WS /catkin_ws


# install deps
RUN apt-get update && apt-get install -y --no-install-recommends \
    tmux \
    ros-melodic-serial \
    git build-essential \
    cmake clang \
    && echo "source /opt/ros/melodic/setup.bash" >> /root/.bashrc 



# Set the correct ROS environment variables so we can use ROS.
RUN /bin/echo 'export ROS_HOSTNAME=localhost' >> /root/.bashrc
RUN /bin/echo 'export ROS_MASTER_URI=http://localhost:11311 ' >> /root/.bashrc



WORKDIR /ros-docker/catkin_ws
ENTRYPOINT /bin/bash




