#!/bin/sh

source devel/setup.bash
rosrun msg_gen msg_gen_node &

i=1
while [ "$i" -le "$1" ]; do
./devel/lib/ver_env/ver_env_node --milpUsageThreshold 0.9 --milpResponsivnessThreshold 0 --topicPrefix robot/ __name:="my_node$i" &
#gdb -ex run -ex backtrace --args ./devel/lib/ver_env/ver_env_node --milpUsageThreshold 0.9 --milpResponsivnessThreshold 0 --topicPrefix robot/ __name:="my_node$i" &
#valgrind --track-origins=yes ./devel/lib/ver_env/ver_env_node __name:="my_node$i" &
#valgrind --tool=helgrind --quiet ./devel/lib/ver_env/ver_env_node __name:="my_node$i" &

i=$(($i + 1))
done

read -n1 -r -p "" key

ps -ef | grep 'msg_gen' | grep -v grep | awk '{print $2}' | xargs -r kill -9
ps -ef | grep 'ver_env' | grep -v grep | awk '{print $2}' | xargs -r kill -9
