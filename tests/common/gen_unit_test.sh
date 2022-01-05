#!/bin/bash

function gen_cpp() {
	sed -e s/_TEMPLATE_UNIT_TEST_NAME_/$2/g common/template/unit_test.cpp > $1/$2.cpp
}

function gen_nsl() {
	sed -e s/_TEMPLATE_UNIT_TEST_NAME_/$2/g common/template/unit_test.nsl > $1/$2.nsl
}

if [ $# -ne 1 ]; then
	echo "Not sufficent arguments"
	echo "$0 name_of_unittest"
	exit 1
fi

test_dir_name=$1_test
testname=$1_unit_test

if [ ! -d $test_dir_name ]; then
	mkdir $test_dir_name
fi

gen_cpp $test_dir_name $testname
gen_nsl $test_dir_name $testname
