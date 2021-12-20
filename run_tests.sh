#!/bin/bash

source image/scripts/env.sh

pushd tests &> /dev/null

ret=0
for i in *; do 
	pushd $i &> /dev/null
		make all
		./$i
		ret=$((ret+$?))
	popd &> /dev/null
done
		
popd &> /dev/null
exit $ret
