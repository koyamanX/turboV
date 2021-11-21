#!/bin/bash
docker run -it --rm \
    --net host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --privileged \
    -v /sys:/sys:ro \
    -v /opt/intelFPGA_lite/20.1:/opt/intelFPGA_lite/latest \
	storm_dev:v1.0 $1
