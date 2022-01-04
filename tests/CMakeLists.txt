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
		DEPENDS ${nsl_depends_list}
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
	"-I${CMAKE_CURRENT_BINARY_DIR}"
)
list(APPEND CXX_FLAGS
	"-I${CMAKE_CURRENT_SOURCE_DIR}/common"
	"-I/usr/src/googletest/googletest/include"
	"-O3"
)
list(APPEND LDFLAGS
	"-lgtest"
)

function(add_verilator module_name)
	add_custom_target(V${module_name}
		COMMAND verilator ${verilator_flags} ${verilator_include} *.v --top-module ${module_name} --exe ${CMAKE_CURRENT_SOURCE_DIR}/${module_name}.cpp -CFLAGS ${CXX_FLAGS} -LDFLAGS ${LDFLAGS}
		COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/obj_dir && make -f V${module_name}.mk V${module_name} -j$(nproc)
		DEPENDS
			${CMAKE_CURRENT_BINARY_DIR}/${module_name}.v
			${ARGN}
	)
endfunction()

add_subdirectory(register_file_test)
add_subdirectory(ifetch_unit_test)
