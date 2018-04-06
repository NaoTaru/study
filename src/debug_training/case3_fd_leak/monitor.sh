#!/bin/bash
set -x

PID=`ps x | grep -v grep | grep "open_loop" | awk '{ print $1 }'`

ls /proc/$PID/fd
