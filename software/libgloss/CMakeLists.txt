enable_language(C ASM)
set(CMAKE_C_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_LINKER /opt/riscv/bin/riscv32-unknown-elf-gcc)
set(CMAKE_C_FLAGS "-march=rv32i -mabi=ilp32 -nostartfiles -nostdlib -nostdinc -nodefaultlibs -static")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/link.ldS")

include_directories($ENV{RISCV}/${RISCV_TOOL_PREFIX}/include)
include_directories($ENV{RISCV}/lib/gcc/${RISCV_TOOL_PREFIX}/${RISCV_TOOL_VERSION}/include)

add_library(libgloss_turboV STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/libgloss_turboV.c
	${CMAKE_CURRENT_SOURCE_DIR}/nanosleep.c
	${CMAKE_CURRENT_SOURCE_DIR}/sbrk.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_access.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_close.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_exit.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_faccessat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_fstatat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_fstat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_gettimeofday.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_link.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_lseek.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_lstat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_openat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_open.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_read.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_stat.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_unlink.c
	${CMAKE_CURRENT_SOURCE_DIR}/sys_write.c
	${CMAKE_CURRENT_SOURCE_DIR}/times.c
	${CMAKE_CURRENT_SOURCE_DIR}/trap.c
	${CMAKE_CURRENT_SOURCE_DIR}/uart.c
	${CMAKE_CURRENT_SOURCE_DIR}/trap_handler.S
	${CMAKE_CURRENT_SOURCE_DIR}/crt0.S
)

set_target_properties(libgloss_turboV PROPERTIES LINKER_LANGUAGE C)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.elf
#    PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#    CONFIGURATIONS Debug
#    RUNTIME DESTINATION Debug/${test_name}
#)
