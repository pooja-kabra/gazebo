# gazebo
Working with Gazebo
# Simple obstacle avoidence behavior on Turtlebot3
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Simple turtle bot obstacle avoidance ROS package. It uses the laser scan published data to check for obstruction in its path to avoid it. Turtle bot simple rotates when obtructed untill finds clear safe way to traverse. 

## Dependencies 
The dependencies of this repository are:

```
* Ubuntu 18.04
* ROS Melodic Kame
* Turtlebot Packages
```

Before proceedigng to install ROS, ensure that version of Ubuntu is 16.04. To install ROS follow the steps given below:

```
$ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
$ sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
$ sudo apt-get update
$ sudo apt-get install ros-melodic-desktop-full
```

After installation of ROS, the next step is to initialize and install its dependencies using following commands:

```
$ rosdep init
$ rosdep update 
```

The next step is to setup ROS environment which can be done using following commands:

```
$ echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
```

Following the environment setup, next step is to create the workspace.

```
$ cd <path where workspace needs to be created>
$ mkdir -p <name of workspace>
$ cd <workspace>
<workspace>$ catkin_make
```

Just like the path of the ROS was sourced in *.bashrc* file, same needs to be done for the workspace by writing `source <path to workspace>/devel/setup.bash` at the end of the *.bashrc* file.
This avoids the need to source every time one needs to use workspace's packages.

Other dependency for this repository is *turtlebot* packages which allow the use of turtlebot in gazebo. Please follow the instructions given below to install the packages:
```
<home> sudo apt-get install ros-melodic-turtlebot-*
```
The command above installs all turtlebot packages instead of going through each of them one at a time. 

## Building the code

The code can be built by cloning the repository and executing following steps:
```
<home>$ cd <workspace>/src
<workspace>/src$ git clone https://github.com/pooja-kabra/walker
<workspace>/src$ cd ..
<workspace>$ catkin_make 
```


### Running using *roslaunch* 
The launch file in this repository launches two things, turtlebot_world and the turtlebot_walker_node. 
```
<home>$ roslaunch walker walker.launch 
```

Please note here that it is not necessary to start *rosmaster* node while using *launch* file. It starts when the file is launched if it is not running. The command above will launch the node with default string in the launch file. 

### Recording *bag* file using the launch file

`turtlebot_walker` launch file of this package accepts a flag `record` that can be used to record the bag file which will record all the data that is being published. By default, the launch file will not record a *bag* file. It will save the file in `results` directory. This can be done using following commands:
```
<home>$ roslaunch walker turtlebot_walker.launch record:=true
```

>NOTE: The launch file doesn't record any data related to *camera*.

### Playback *bag* file
The provided sample bag file or any recorded bag file using the instructions provided above can be played by following the commands given below:
```
<home>$ cd <worskpace>/src/turtlebot_walker/results
<../results>$ rosbag play walker.bag
```

One can use, *space* key to toggle between pause and play. Pressing *s* key will skip to the next nearest second value. 

While playing the bag file, one can *echo* a topic to see what is being published on the that topic and to analyze the behavior of the robot. To do this, please ensure that the bag file is being played. In other terminal execute the following command:
```
<home>$ rostopic echo <topic name>
```

For example, if one wants to check the topic `/cmd_vel` this can be one as follows after running the bag file:
```
<home>$ rostopic echo /cmd_vel/
```

>NOTE: Please note that Gazebo should not be running while playing the bag file.