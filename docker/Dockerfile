FROM osrf/ros:melodic-desktop

# install ros tutorials packages
RUN apt-get update && apt-get install -y \
    tmux \
    git build-essential \
    cmake clang \
    && echo "source /catkin_ws/devel/setup.bash" >> /root/.bashrc

# Set the correct ROS environment variables so we can use ROS.
RUN /bin/echo 'export ROS_HOSTNAME=localhost' >> /root/.bashrc
RUN /bin/echo 'export ROS_MASTER_URI=http://localhost:11311 ' >> /root/.bashrc


WORKDIR /catkin_ws/