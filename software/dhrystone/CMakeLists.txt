set(test_name dhrystone)

enable_language(C ASM)
set(CMAKE_C_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_LINKER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_C_FLAGS "-march=rv32i -mabi=ilp32 -nostartfiles")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.ldS")

include_directories(
	$ENV{RISCV}/${RISCV_TOOL_PREFIX}/include
	$ENV{RISCV}/lib/gcc/${RISCV_TOOL_PREFIX}/${RISCV_TOOL_VERSION}/include
)
add_executable(${test_name}.elf
    ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}_main.c
)
link_directories(${test_name}.elf
	$ENV{RISCV}/${RISCV_TOOL_PREFIX}/lib
	$ENV{RISCV}/lib/gcc/${RISCV_TOOL_PREFIX}/${RISCV_TOOL_VERSION}/lib
	${CMAKE_SOURCE_DIR}/software/libgloss
)
target_link_libraries(${test_name}.elf
	c
	m
	g
	gcc
	libgloss_turboV
)
set_target_properties(${test_name}.elf PROPERTIES LINKER_LANGUAGE C)

add_test(NAME ${test_name}
    COMMAND ${CMAKE_BINARY_DIR}/Debug/turboVSim/turboVSim ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.elf
)
set_property(TEST ${test_name} PROPERTY TIMEOUT 10)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.elf
    PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    CONFIGURATIONS Debug
    RUNTIME DESTINATION Debug/${test_name}
)
