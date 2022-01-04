add_nsl_test(ifetch_unit_test ${CMAKE_CURRENT_SOURCE_DIR}/ifetch_unit_test.nsl ${CMAKE_CURRENT_BINARY_DIR}/ifetch_unit_test.v)
add_verilator(ifetch_unit_test core wishbone integration)

add_test(NAME ifetch_unit_test
	COMMAND ${CMAKE_BINARY_DIR}/Debug/ifetch_unit_test
	CONFIGURATION Debug
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/Vifetch_unit_test
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug
	RENAME ifetch_unit_test
)
