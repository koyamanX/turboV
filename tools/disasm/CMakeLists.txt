project(disasm)

include_directories("/opt/riscv/x86_64-pc-linux-gnu/riscv32-elflittle/include/")
link_directories("/opt/riscv/x86_64-pc-linux-gnu/riscv32-elflittle/lib/")
add_executable(disasm ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
target_link_libraries(disasm opcodes bfd iberty z dl)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/disasm
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	CONFIGURATIONS Debug
	RUNTIME DESTINATION Debug/tools/disasm
)
