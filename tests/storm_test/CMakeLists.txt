set(test_name storm_unit_test)
set(bootrom_name "${test_name}_bootrom")

add_nsl_test(${test_name} ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.nsl ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.v)
add_verilator(${test_name} core wishbone integration ${bootrom_name}.hex)

add_test(NAME ${test_name}
	COMMAND ${CMAKE_BINARY_DIR}/Debug/${test_name}/${test_name}
	CONFIGURATION Debug
)
enable_language(C ASM)
set(CMAKE_C_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER /opt/riscv/bin/riscv32-unknown-elf-as)
set(CMAKE_LINKER /opt/riscv/bin/riscv32-unknown-elf-ld)
set(CMAKE_C_FLAGS "-march=rv32i -nostartfiles")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/bootrom.ldS")
add_executable(${bootrom_name}.elf
	${CMAKE_CURRENT_SOURCE_DIR}/bootrom.S
)
set_target_properties(${bootrom_name}.elf PROPERTIES LINKER_LANGUAGE C)

add_custom_target(${bootrom_name}.hex
	COMMAND /opt/riscv/bin/riscv32-unknown-elf-objcopy -O verilog ${bootrom_name}.elf ${bootrom_name}.hex
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../tools/gen_rom_data.py ${CMAKE_CURRENT_BINARY_DIR}/${bootrom_name}.hex 8
	DEPENDS ${bootrom_name}.elf
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/V${test_name}
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/${test_name}
	RENAME ${test_name}
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom0.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom1.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom2.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom3.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom4.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom5.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom6.hex
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rom7.hex
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/${test_name}
)
