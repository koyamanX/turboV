set(test_name rom_test)

add_nsl_test(${test_name} ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.nsl ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.v)
add_verilator(${test_name} core wishbone integration)

add_test(NAME ${test_name}
	COMMAND ${CMAKE_BINARY_DIR}/Debug/${test_name}/${test_name}
	CONFIGURATION Debug
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/V${test_name}
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/${test_name}
	RENAME ${test_name}
)
