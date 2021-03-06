# ROS Docker 

A simple template project for [dockerizing](https://www.docker.com/) your [ROS](http://www.ros.org/) code. Have your ROS project set up and running in 3 minutes by putting your catkin workspace in `catkin_ws` and running:

```
sudo apt-get install docker    # install the docker
git clone https://github.com/Basavaraj-PN/ROS-ON-DOCKER.git    #clone the repo
docker/build                  # this will build the docker container
docker/start                    # this will run or start the docker container
docker/into                   # to enter docker container in terminal 
catkin_make                    # to compile the catkin_ws
```

And that's it!

## FAQ

### How can I use a different version of ROS?

This works with [any supported version of ROS](https://hub.docker.com/_/ros/), just edit the top line of the Dockerfile. For example, if you want ROS Melodic:

```
FROM osrf/ros:melodic-desktop
```

### Can I use my favourite IDE/editor with this?

Yup! The `catkin_ws` directory is mounted as a volume inside the container, so you can edit your code as usual, and it will be automatically synced with the container.

### Where is my `catkin_ws` workspace mounted inside the container?

Inside the container, the `catkin_ws` folder will be mounted at root (`/ros-docker/catkin_ws`). 

### How do I install additional packages / dependencies / tools?

Add your dependencies to the RUN command in the `Dockerfile` (this example installs `tmux` and `ros-melodic-serial` packages using apt, you can add any additional commands or packages you like).

### I need another terminal window in the container!

I recommend [tmux](https://robots.thoughtbot.com/a-tmux-crash-course) as an easy way to manage multiple shells in ROS.

However, if you really want multiple terminal windows instead, you can open a new terminal window on your host computer and run:

```
docker/into
```

### I want to run a different command on container startup!

You can give your command as an argument to `script/run`, for example:

```
script/run roslaunch example.launch
```

### How do I pass a device (e.g. serial, joystick) to the container?

Edit `script/run` and add the line `--device=/dev/ttyUSB0 \` (changing the `/dev` path to match the path to your device).

### How can I easily coordinate multiple containers and have them talk to one another?

The `docker-compose` tool is the standard way to run multiple containers together: https://docs.docker.com/compose/overview/

