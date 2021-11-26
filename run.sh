#!/bin/bash
docker run -it --rm \
    --net host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --privileged \
    -v /sys:/sys:ro \
    -v /opt/intelFPGA_lite/20.1:/opt/intelFPGA_lite/latest \
	-v $(pwd)/src:/root/src \
	-v $(pwd)/tests:/root/tests \
	-v $(pwd)/storm.mk:/root/storm.mk \
	storm_dev:v1.0 $1
