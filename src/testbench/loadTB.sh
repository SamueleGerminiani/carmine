#!/bin/sh

source devel/setup.bash

timeout 1 rostopic pub /ver_env/overhead/edge1 std_msgs/Float64 "data: 350.0"
sleep 10
timeout 1 rostopic pub /ver_env/overhead/edge1 std_msgs/Float64 "data: 400.0"
timeout 1 rostopic pub /ver_env/overhead/desktop1 std_msgs/Float64 "data: 800.0"
sleep 10
timeout 1 rostopic pub /ver_env/overhead/edge1 std_msgs/Float64 "data: 0.0"
timeout 1 rostopic pub /ver_env/overhead/desktop1 std_msgs/Float64 "data: 0.0"
sleep 10


