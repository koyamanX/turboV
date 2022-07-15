#!/bin/bash
set -ex

git clone https://github.com/koyamanX/chibicc
pushd chibicc &> /dev/null
    make
    cp chibicc /bin
popd &> /dev/null
rm -rf chibicc
