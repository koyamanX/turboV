#!/bin/bash
set -ex

git clone https://github.com/nlohmann/json
pushd json &> /dev/null
	mkdir build
	pushd build &> /dev/null
		cmake ..
		make -j$(nproc)
		make install
	popd &> /dev/null
popd &> /dev/null
rm -rf json
