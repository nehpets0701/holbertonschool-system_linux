#!/bin/sh
#sends sigquit to given process

if [ $# -ne 1 ]; then
    echo "Usage: $0 <pid>"
    exit 1
fi

kill -QUIT $1
