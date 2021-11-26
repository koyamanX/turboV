#!/bin/bash

pushd /usr/src/googletest &> /dev/null
	mkdir build
	pushd build &> /dev/null
		cmake ../
		make
		make install
	popd
	rm -rf build
popd

