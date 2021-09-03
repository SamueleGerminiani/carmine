#!/bin/sh

source devel/setup.bash
rosrun msg_gen msg_gen_node &

i=1
while [ "$i" -le "$1" ]; do
  rosrun verification_env verification_env_node __name:="my_node$i" &
  i=$(($i + 1))
done

read -n1 -r -p "" key

ps -ef | grep 'msg_gen' | grep -v grep | awk '{print $2}' | xargs -r kill -9
ps -ef | grep 'verification_env' | grep -v grep | awk '{print $2}' | xargs -r kill -9
