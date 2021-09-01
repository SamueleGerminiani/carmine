#!/bin/sh
ps -ef | grep 'verification_env' | grep -v grep | awk '{print $2}' | xargs -r kill -9
ps -ef | grep 'msg_gen' | grep -v grep | awk '{print $2}' | xargs -r kill -9
