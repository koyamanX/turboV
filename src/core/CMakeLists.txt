add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/icache.nsl ${CMAKE_CURRENT_BINARY_DIR}/icache.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/ifetch_unit.nsl ${CMAKE_CURRENT_BINARY_DIR}/ifetch_unit.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/inst_buffer.nsl ${CMAKE_CURRENT_BINARY_DIR}/inst_buffer.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/register_file.nsl ${CMAKE_CURRENT_BINARY_DIR}/register_file.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/imm_gen.nsl ${CMAKE_CURRENT_BINARY_DIR}/imm_gen.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/instruction_decoder.nsl ${CMAKE_CURRENT_BINARY_DIR}/instruction_decoder.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/alu32.nsl ${CMAKE_CURRENT_BINARY_DIR}/alu32.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/turboV.nsl ${CMAKE_CURRENT_BINARY_DIR}/turboV.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/reorder_buffer.nsl ${CMAKE_CURRENT_BINARY_DIR}/reorder_buffer.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/reservation_station.nsl ${CMAKE_CURRENT_BINARY_DIR}/reservation_station.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/bru32.nsl ${CMAKE_CURRENT_BINARY_DIR}/bru32.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/reservation_station_in_order_2way.nsl ${CMAKE_CURRENT_BINARY_DIR}/reservation_station_in_order_2way.v)

add_custom_target(core
	DEPENDS
		${CMAKE_CURRENT_BINARY_DIR}/icache.v
		${CMAKE_CURRENT_BINARY_DIR}/ifetch_unit.v
		${CMAKE_CURRENT_BINARY_DIR}/inst_buffer.v
		${CMAKE_CURRENT_BINARY_DIR}/register_file.v
		${CMAKE_CURRENT_BINARY_DIR}/imm_gen.v
		${CMAKE_CURRENT_BINARY_DIR}/instruction_decoder.v
		${CMAKE_CURRENT_BINARY_DIR}/alu32.v
		${CMAKE_CURRENT_BINARY_DIR}/turboV.v
		${CMAKE_CURRENT_BINARY_DIR}/reorder_buffer.v
		${CMAKE_CURRENT_BINARY_DIR}/reservation_station.v
		${CMAKE_CURRENT_BINARY_DIR}/bru32.v
		${CMAKE_CURRENT_BINARY_DIR}/reservation_station_in_order_2way.v
)
