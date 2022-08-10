#!/bin/sh
cd ../
./generate_env.sh $1 $2
cd build 
rm -rf ~/catkin_ws/src/ver_env/ 
cp -r ../output/ver_env/ ~/catkin_ws/src/ 

if [ "$2" == "--debug" ]; then
    rm -rf ~/catkin_ws/src/msg_gen 
    cp -r ../src/testbench/msg_gen ~/catkin_ws/src/ 
    rm -rf ~/catkin_ws/src/cpu_oh_gen 
    cp -r ../src/testbench/cpu_oh_gen ~/catkin_ws/src/
fi

