set(test_name csr_inst_test)

enable_language(C ASM)
set(CMAKE_C_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_LINKER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_C_FLAGS "-march=rv32i -mabi=ilp32 -nostartfiles -nostdlib -nostdinc -nodefaultlibs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.ldS")

add_executable(${test_name}.elf
	${CMAKE_CURRENT_SOURCE_DIR}/crt0.S
	${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.S
)
include_directories(${CMAKE_SOURCE_DIR}/tests/utils)
set_target_properties(${test_name}.elf PROPERTIES LINKER_LANGUAGE C)

add_test(NAME ${test_name}
	COMMAND ${CMAKE_BINARY_DIR}/Debug/turboVSim/turboVSim ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.elf
)
set_property(TEST ${test_name} PROPERTY TIMEOUT 10)
set_property(TEST ${test_name} PROPERTY WILL_FAIL TRUE)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.elf
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/${test_name}
)
