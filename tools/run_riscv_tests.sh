#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Insufficent arguments"
    exit 1
fi
simulator=$1
test_dir=$2

if [ ! -d "$test_dir" ]; then
    echo "riscv-tests is not found"
    exit 1
fi

test_variants=("rv32ui-p")
for test_variant in ${test_variants[@]}; do
    test_name_list=$(find $test_dir -name "$test_variant-*" -not -name "$test_variant-*.dump")
    for test_name in $test_name_list; do
        if [ ! -d "logs" ]; then
            mkdir logs
        fi
        timeout 8 ./$simulator $test_name > logs/$(basename $test_name).log
        if [ $? -eq 1 ]; then
            echo "$test_name passed"
        else
            echo "$test_name failed"
        fi
    done
done
