#define PACKAGE "bfd"
#include <bfd.h>
#include <stdio.h>
#include <dis-asm.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    disassembler_ftype disasm = NULL;
    struct disassemble_info disasm_info = {};
    uint32_t inst;
    uint32_t pc = 0;
    FILE *stream = stdin;
    char *line;
    ssize_t nread = 0;
    size_t len = 0;
    uint32_t prd;
    uint32_t prs1;
    uint32_t prs2;

    init_disassemble_info(&disasm_info, stdout, (fprintf_ftype) fprintf);
    disasm_info.arch = bfd_arch_riscv;
    disasm_info.mach = bfd_mach_riscv32;
    disasm_info.buffer_length = 0x4;
    disasm_info.buffer = (uint8_t*)&inst;
    disasm_info.read_memory_func = buffer_read_memory;
    disassemble_init_for_target(&disasm_info);
    disasm = disassembler(bfd_arch_riscv, false, bfd_mach_riscv32, NULL);

    line = malloc(sizeof(char) * BUFSIZ);
    while((nread = getline(&line, &len, stream)) != -1) {
        sscanf(line, "%x: DASM(%x) (prd: %x, prs1: %x, prs2: %x)", &pc, &inst, &prd, &prs1, &prs2);
        disasm_info.buffer_vma = pc;
        printf("%08x: ", pc);
        disasm(pc, &disasm_info);
        puts("");
        printf("prd: %02x, prs1: %02x, prs2: %02x", prd, prs1, prs2);
        puts("");
    }
    fclose(stream);

    return 0;
}
