#!/bin/bash
docker run -it --rm \
    --net host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --privileged \
    -v /sys:/sys:ro \
    -v /opt/intelFPGA_lite/20.1:/opt/intelFPGA_lite/latest \
	-v $(pwd)/src:/root/src \
	-v $(pwd)/simulator:/root/simulator \
	-v $(pwd)/tools:/root/tools \
	-v $(pwd)/tests:/root/tests \
    -v $(pwd)/image/scripts/env.sh:/root/.env.sh \
	-v $(pwd)/CMakeLists.txt:/root/CMakeLists.txt \
	-v $(pwd)/build:/root/build \
	koyamanx/turbov_dev:v1.2 $1
