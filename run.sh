#!/bin/bash
docker run -it --rm \
    --net host \
    -e DISPLAY=$DISPLAY \
	-e RISCV=/opt/riscv \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --privileged \
    -v /sys:/sys:ro \
    -v /opt/intelFPGA_lite/21.1:/opt/intelFPGA_lite/latest \
	-v $(pwd):/work \
	-w /work \
	koyamanx/turbov_dev:v1.4 $1
