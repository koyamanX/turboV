set(top_module turboVSim)
set(bootrom_name "${top_module}_bootrom")

add_nsl_test(${top_module} ${CMAKE_CURRENT_SOURCE_DIR}/${top_module}.nsl ${CMAKE_CURRENT_BINARY_DIR}/${top_module}.v)
add_verilator(${top_module} core wishbone integration)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/obj_dir/V${top_module}
    PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    CONFIGURATIONS Debug
    RUNTIME DESTINATION Debug/${top_module}
    RENAME ${top_module}
)
