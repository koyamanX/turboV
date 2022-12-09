include(ExternalProject)
ExternalProject_Add(
    riscv-tests
    GIT_REPOSITORY https://github.com/riscv-software-src/riscv-tests
    GIT_TAG 7530d52174988076c182a9e6cd43eca7a574925f
    INSTALL_DIR ${CMAKE_BINARY_DIR}/Debug/
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR>
    BUILD_COMMAND make XLEN=32
    INSTALL_COMMAND make install
)
add_subdirectory(software_interrupt_test)
add_subdirectory(timer_interrupt_test)
add_subdirectory(csr_inst_test)
add_subdirectory(instruction_address_misaligned_test)

set(ISA_DIR ${CMAKE_BINARY_DIR}/Debug/share/riscv-tests/isa)
set(SIMULATOR ${CMAKE_BINARY_DIR}/Debug/turboVSim/turboVSim)

list(APPEND rv32ui_p
    rv32ui-p-add
    rv32ui-p-addi
    rv32ui-p-and
    rv32ui-p-andi
    rv32ui-p-auipc
    rv32ui-p-beq
    rv32ui-p-bge
    rv32ui-p-bgeu
    rv32ui-p-blt
    rv32ui-p-bltu
    rv32ui-p-bne
#   rv32ui-p-fence_i
    rv32ui-p-jal
    rv32ui-p-jalr
    rv32ui-p-lb
    rv32ui-p-lbu
    rv32ui-p-lh
    rv32ui-p-lhu
    rv32ui-p-lui
    rv32ui-p-lw
    rv32ui-p-or
    rv32ui-p-ori
    rv32ui-p-sb
    rv32ui-p-sh
    rv32ui-p-simple
    rv32ui-p-sll
    rv32ui-p-slli
    rv32ui-p-slt
    rv32ui-p-slti
    rv32ui-p-sltiu
    rv32ui-p-sltu
    rv32ui-p-sra
    rv32ui-p-srai
    rv32ui-p-srl
    rv32ui-p-srli
    rv32ui-p-sub
    rv32ui-p-sw
    rv32ui-p-xor
    rv32ui-p-xori
)
list(APPEND rv32mi_p
#   rv32mi-p-breakpoint
    rv32mi-p-csr
    rv32mi-p-illegal
    rv32mi-p-ma_fetch
#   rv32mi-p-ma_addr
    rv32mi-p-mcsr
    rv32mi-p-sbreak
    rv32mi-p-scall
    rv32mi-p-shamt
)

list(APPEND will_fail_tests
)

set(riscv_tests ${rv32ui_p} ${rv32mi_p})

foreach(riscv_test ${riscv_tests})
    get_filename_component(riscv_test_name ${riscv_test} NAME)
    add_test(NAME ${riscv_test_name} COMMAND ${SIMULATOR} ${ISA_DIR}/${riscv_test})
    set_property(TEST ${riscv_test_name} PROPERTY TIMEOUT 10)
endforeach()

foreach(will_fail_test ${will_fail_tests})
    set_property(TEST ${will_fail_test} PROPERTY WILL_FAIL TRUE)
endforeach()

