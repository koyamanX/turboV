include(ExternalProject)
ExternalProject_Add(
    riscv-tests
    GIT_REPOSITORY https://github.com/riscv-software-src/riscv-tests
    INSTALL_DIR ${CMAKE_BINARY_DIR}/Debug/
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR>
    BUILD_COMMAND make XLEN=32
    INSTALL_COMMAND make install
)
add_subdirectory(software_interrupt_test)

set(ISA_DIR ${CMAKE_BINARY_DIR}/Debug/share/riscv-tests/isa)
set(SIMULATOR ${CMAKE_BINARY_DIR}/Debug/turboVSim/turboVSim)

file(GLOB rv32ui_p "${ISA_DIR}/rv32ui-p-*")
file(GLOB rv32mi_p "${ISA_DIR}/rv32mi-p-*")
set(riscv_tests ${rv32ui_p} ${rv32mi_p})
list(FILTER riscv_tests EXCLUDE REGEX "\.dump")

foreach(riscv_test ${riscv_tests})
    get_filename_component(riscv_test_name ${riscv_test} NAME)
    add_test(NAME ${riscv_test_name} COMMAND ${SIMULATOR} ${riscv_test})
    set_property(TEST ${riscv_test_name} PROPERTY TIMEOUT 10)
endforeach()
