set(top_module turboVSim)
set(bootrom_name "${top_module}_bootrom")

add_nsl_test(${top_module} ${CMAKE_CURRENT_SOURCE_DIR}/${top_module}.nsl ${CMAKE_CURRENT_BINARY_DIR}/${top_module}.v)
add_verilator(${top_module} core wishbone integration ${bootrom_name}.hex)

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
	COMMAND ${CMAKE_SOURCE_DIR}/tools/gen_rom_data.py ${CMAKE_CURRENT_BINARY_DIR}/${bootrom_name}.hex 8
	DEPENDS ${bootrom_name}.elf
)


install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/V${top_module}
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/${top_module}
	RENAME ${top_module}
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
	RUNTIME DESTINATION Debug/${top_module}
)
