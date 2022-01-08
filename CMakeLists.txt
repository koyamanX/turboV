cmake_minimum_required(VERSION 3.18)

project(storm)
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

add_subdirectory(src)
add_subdirectory(tests)
