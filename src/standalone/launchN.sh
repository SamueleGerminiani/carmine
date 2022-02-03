#!/bin/sh

source devel/setup.bash
i=1
while [ "$i" -le "$1" ]; do
./devel/lib/ver_env/ver_env_node --disableNotifications --milpUsageThreshold 0.9 --milpResponsivnessThreshold 0 --topicPrefix robot/ __name:="server$i" &
i=$(($i + 1))
done

read -n1 -r -p "" key

ps -ef | grep 'ver_env' | grep -v grep | awk '{print $2}' | xargs -r kill -9
