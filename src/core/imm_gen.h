#ifndef IMM_GEN_H
#define IMM_GEN_H

declare imm_gen {
    input inst[32];
    output imm[32];

    func_in i_type(inst): imm;
    func_in s_type(inst): imm;
    func_in b_type(inst): imm;
    func_in u_type(inst): imm;
    func_in j_type(inst): imm;
}

#endif
