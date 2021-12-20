#!/bin/bash

source image/scripts/env.sh

pushd tests &> /dev/null

for i in *; do 
	if [ $i = common ]; then
		continue
	fi
	pushd $i &> /dev/null
		make all
		./$i
		ret=$((ret+$?))
	popd &> /dev/null
done
		
popd &> /dev/null
