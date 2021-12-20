#!/bin/bash

source image/scripts/env.sh

pushd tests &> /dev/null

for i in *; do 
	pushd $i &> /dev/null
		make
	popd &> /dev/null
done
		
popd &> /dev/null
