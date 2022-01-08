add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/icache.nsl ${CMAKE_CURRENT_BINARY_DIR}/icache.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/ifetch_unit.nsl ${CMAKE_CURRENT_BINARY_DIR}/ifetch_unit.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/inst_buffer.nsl ${CMAKE_CURRENT_BINARY_DIR}/inst_buffer.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/register_file.nsl ${CMAKE_CURRENT_BINARY_DIR}/register_file.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/imm_gen.nsl ${CMAKE_CURRENT_BINARY_DIR}/imm_gen.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/instruction_decoder.nsl ${CMAKE_CURRENT_BINARY_DIR}/instruction_decoder.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/alu32.nsl ${CMAKE_CURRENT_BINARY_DIR}/alu32.v)

add_custom_target(core
	DEPENDS
		${CMAKE_CURRENT_BINARY_DIR}/icache.v
		${CMAKE_CURRENT_BINARY_DIR}/ifetch_unit.v
		${CMAKE_CURRENT_BINARY_DIR}/inst_buffer.v
		${CMAKE_CURRENT_BINARY_DIR}/register_file.v
		${CMAKE_CURRENT_BINARY_DIR}/imm_gen.v
		${CMAKE_CURRENT_BINARY_DIR}/instruction_decoder.v
		${CMAKE_CURRENT_BINARY_DIR}/alu32.v
)
