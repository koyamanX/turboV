add_nsl_test(register_file_unit_test ${CMAKE_CURRENT_SOURCE_DIR}/register_file_unit_test.nsl ${CMAKE_CURRENT_BINARY_DIR}/register_file_unit_test.v)

add_custom_target(register_file_unit_test
	COMMAND verilator ${verilator_flags} ${verilator_include} *.v --top-module register_file_unit_test --exe ${CMAKE_CURRENT_SOURCE_DIR}/register_file_unit_test.cpp -CFLAGS ${CXX_FLAGS} -LDFLAGS ${LDFLAGS}
	COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/obj_dir && make -f Vregister_file_unit_test.mk Vregister_file_unit_test
	DEPENDS
		core
		wishbone
		integration
		${CMAKE_CURRENT_BINARY_DIR}/register_file_unit_test.v
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/Vregister_file_unit_test
	PERMISSIONS OWNER_READ OWNER_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/bin/register_file_unit_test
)
