list(APPEND NSLOPTS
	"-clock_name CLK_I"
	"-reset_name RST_I"
)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/wishbone_master.nsl ${CMAKE_CURRENT_BINARY_DIR}/wishbone_master.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/wishbone_slave.nsl ${CMAKE_CURRENT_BINARY_DIR}/wishbone_slave.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/wishbone_syscon.nsl ${CMAKE_CURRENT_BINARY_DIR}/wishbone_syscon.v)

add_custom_target(wishbone
	DEPENDS
		${CMAKE_CURRENT_BINARY_DIR}/wishbone_master.v
		${CMAKE_CURRENT_BINARY_DIR}/wishbone_slave.v
		${CMAKE_CURRENT_BINARY_DIR}/wishbone_syscon.v
)
