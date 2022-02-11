.. index:: Issue stage

Issue Stage
-----------

.. list-table:: Abbreviation
	:widths: 25 25
	:header-rows: 1
	
	* - Name
	  - Description
	* - ROB
	  - Reorder Buffer
	* - RS
	  - Reservation Station
	* - register_status_table
	  - Hold register status
	* - register_map_table
	  - Hold register mappings of architectural register to ROB
	* - GPR
	  - General Purpose Register
	* - PC
	  - Program Counter
	* - Inst
	  - Instruction
	* - Opcode
	  - Inst.opcode
	* - rd
	  - Inst.rd
	* - rs1
	  - Inst.rs1
	* - rs2
	  - Inst.rs2
	* - imm
	  - Inst.imm

ALU Instruction
^^^^^^^^^^^^^^^

Instructions which uses ALU are issued to ALU pipes.
(e.g. Opcodes variants of OP, OP_IMM, AUIPC, LUI, JAL, JALR)

.. code-block:: c
	:linenos:

	if((!ROB.full) && (!RS.full)) {
		if(opcode == LUI) {
			Vj = 0;
			Qj = 0;
		} else if(opcode == JAL || AUIPC) {
			Vj = PC;
			Qj = 0;
		} else {
			if(rs1 == 0) {
				Vj = 0;
				Qj = 0;
			} else if(register_status_table[rs1] == BUSY) {
				if(ROB.read_operandA(register_map_table[rs1]) == BUSY) {
					Vj = 0;
					Qj = register_map_table[rs1];
				} else {
					Vj = ROB.read_oprandA_value;
					Qj = 0;
				}
			} else {
				Vj = GPR.readA(rs1);
				Qj = 0;
			}
		}

		if(opcode == OP) {
			if(rs2 == 0) {
				Vk = 0;
				Qk = 0;
			} else if(register_status_table[rs2] == BUSY) {
				if(ROB.read_operandB(register_map_table[rs2] == BUSY) {
					Vk = 0;
					Qk = register_map_table[rs2];
				} else {
					Vk = ROB.read_operandB_value;
					Qk = 0;
				}
			} else {
				Vk = GPR.readB(rs2);
				Qk = 0;
			}
		} else {
			Vk = imm;
			Qk = 0;
		}

		if(rd != 0) {
			register_map_table[rd] := ROB.tag;
			register_status_table[rd] = BUSY;
		}

		RS.Busy = 1;
		RS.Op = Inst.Opcode;
		RS.Vj = Vj;
		RS.Vk = Vk;
		RS.Qj = Qj;
		RS.Qk = Qk;
		RS.Dest = ROB.tag
		RS.A = 0;
		ROB.Valid = 1;
		ROB.Busy = 1;
		ROB.PC = PC:
		ROB.Inst = Inst;
		ROB.Dest = rd;
		// ROB.Value
		if(opcode == JAL || opcode == JALR) {
			ROB.Jump = 1;
		} else {
			ROB.Jump = 0;
		}
		ROB.Target = PC + imm;
	}

Branch Instruction
^^^^^^^^^^^^^^^^^^

Instructions with opcode == BRANCH are issued to Branch pipes.

.. code-block:: c
	:linenos:

	if((!ROB.full) && (!RS.full)) {
		if(rs1 == 0) {
			Vj = 0;
			Qj = 0;
		} else if(register_status_table[rs1] == BUSY) {
			if(ROB.read_operandA(register_map_table[rs1]) == BUSY) {
				Vj = 0;
				Qj = register_map_table[rs1];
			} else {
				Vj = ROB.read_oprandA_value;
				Qj = 0;
			}
		} else {
			Vj = GPR.readA(rs1);
			Qj = 0;
		}

		if(rs2 == 0) {
			Vk = 0;
			Qk = 0;
		} else if(register_status_table[rs2] == BUSY) {
			if(ROB.read_operandB(register_map_table[rs2] == BUSY) {
				Vk = 0;
				Qk = register_map_table[rs2];
			} else {
				Vk = ROB.read_operandB_value;
				Qk = 0;
			}
		} else {
			Vk = GPR.readB(rs2);
			Qk = 0;
		}

		if(rd != 0) {
			register_map_table[rd] := ROB.tag;
			register_status_table[rd] = BUSY;
		}
		
		RS.Busy = 1;
		RS.Op = Inst.Opcode;
		RS.Vj = Vj;
		RS.Vk = Vk;
		RS.Qj = Qj;
		RS.Qk = Qk;
		RS.Dest = ROB.tag
		RS.A = 0;
		ROB.Valid = 1;
		ROB.Busy = 1;
		ROB.PC = PC:
		ROB.Inst = Inst;
		ROB.Dest = rd;
		// ROB.Value
		ROB.Jump = 0
		ROB.Target = PC + imm;
	}
