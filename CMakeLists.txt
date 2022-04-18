cmake_minimum_required(VERSION 3.18)

project(turboV)
enable_testing()
include(CTest)

set(NSL2VL nsl2vl)
set(IVERILOG iverilog)
set(VERILATOR verilator)
set(GTKWAVE gtkwave)
set(RISCV_TOOLS_PREFIX riscv32-unknown-elf-)
set(INSTALL_DIR release)

list(APPEND NSL_INCLUDE
	"-I${CMAKE_SOURCE_DIR}/src/core"
	"-I${CMAKE_SOURCE_DIR}/src/integration"
	"-I${CMAKE_SOURCE_DIR}/src/wishbone"
	"-I${CMAKE_CURRENT_SOURCE_DIR}"
)
list(APPEND NSL_FLAGS
	"-O2"
)
list(APPEND IVERILOG_FLAGS
	""
)
list(APPEND VERILATOR_FLAGS
	""
)
list(APPEND GTKWAVE_FLAGS
	""
)
list(APPEND CMAKE_CXX_FLAGS
	""
)
# add_nsl_target("src" "out")
# or
# add_nsl_target("src" "out" "depends")
function(add_nsl_target input output)
	#string(REGEX "[.]nsl$" ".v" vfile ${input})
	execute_process(
		COMMAND cpp -MM ${input} ${NSL_INCLUDE}
		COMMAND sed -e "1d"
		COMMAND sed "s/ //"
		OUTPUT_VARIABLE nsl_depends
	)
#string(REPLACE " \\\n" ";" nsl_depends_list ${nsl_depends})
	list(APPEND nsl_depends_list ${ARGN})
	add_custom_command(
		OUTPUT ${output}
		COMMAND nsl2vl ${NSL_FLAGS} ${NSL_INCLUDE} ${input} -o ${output}
		#DEPENDS ${nsl_depends_list}
	)
endfunction()

function(add_nsl_test target input output)
	execute_process(
		COMMAND cpp -MM ${input} ${NSL_INCLUDE}
		COMMAND sed -e "1d"
		COMMAND sed "s/ //"
		OUTPUT_VARIABLE nsl_depends
	)
	string(REPLACE " \\\n" ";" nsl_depends_list ${nsl_depends})
	list(APPEND nsl_depends_list ${ARGN})
	add_custom_command(
		OUTPUT ${output}
		COMMAND nsl2vl ${NSL_FLAGS} ${NSL_INCLUDE} -verisim2 -target ${target} ${input} -o ${output}
		#DEPENDS ${nsl_depends_list}
	)
endfunction()

list(APPEND verilator_flags
	"-cc"
	"-Wno-lint"
	"--trace"
	"--trace-underscore"
	"-Wno-TIMESCALEMOD"
	"-Wno-STMTDLY"
	"-Wno-INFINITELOOP"
	"-O3"
	"--autoflush"
	"-flatten"
)
list(APPEND verilator_include
	"-I${CMAKE_BINARY_DIR}/src/core"
	"-I${CMAKE_BINARY_DIR}/src/wishbone"
	"-I${CMAKE_BINARY_DIR}/src/integration"
	"-I${CMAKE_SOURCE_DIR}/tests/"
	"-I${CMAKE_CURRENT_BINARY_DIR}"
)
list(APPEND CXX_FLAGS
	"-I${CMAKE_SOURCE_DIR}/tests/common"
	"-I/usr/src/googletest/googletest/include"
	"-O3"
)
set(LDFLAGS "-lgtest -lpthread")

function(add_verilator module_name)
	add_custom_target(V${module_name} ALL
		COMMAND verilator ${verilator_flags} ${verilator_include} *.v --top-module ${module_name} --exe ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}.cpp -CFLAGS ${CXX_FLAGS} -LDFLAGS ${LDFLAGS}
		COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/obj_dir && make -f V${module_name}.mk V${module_name} -j$(nproc)
		DEPENDS
			${CMAKE_CURRENT_BINARY_DIR}/${module_name}.v
			${ARGN}
	)
endfunction()

add_subdirectory(src)
add_subdirectory(tests)
