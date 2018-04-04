#!/bin/bash
set -x

PID=`ps x | grep -v grep | grep "malloc_loop" | awk '{ print $1 }'`

rm -f monitor.log

top -b -p $PID -d 2 -n 10 >> monitor.log
