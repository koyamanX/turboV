#!/bin/bash

source /root/.env.sh
simulator=$SIMULATOR_PATH
test_dir=$RISCV_TESTS_PATH

echo $simulator
echo $test_dir

if [ ! -d "$test_dir" ]; then
    echo "riscv-tests is not found"
    exit 1
fi

test_variants=("rv32ui-p")
ret=0
rm -r logs/result.txt
for test_variant in ${test_variants[@]}; do
    test_name_list=$(find $test_dir -name "$test_variant-*" -not -name "$test_variant-*.dump")
    for test_name in $test_name_list; do
        if [ ! -d "logs" ]; then
            mkdir logs
        fi
        timeout 8 $simulator $test_name > logs/$(basename $test_name).log
        if [ $? -eq 1 ]; then
            echo "$test_name passed"
            echo "$test_name passed" >> logs/result.txt
        else
            echo "$test_name failed"
            echo "$test_name failed" >> logs/result.txt
            ret=$((ret+1))
        fi
        cp $test_name.dump logs
        cp turboVSim.vcd logs/$(basename $test_name).vcd
    done
done
exit $ret
