.. index:: Instruction decoder

======================
4. Instruction Decoder
======================

Class Diagram
-------------

.. uml:: _static/plantuml/class_diagram_instruction_decoder.puml

Opcode map
----------

	+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
	| inst[4:2] | 000       | 001       | 010       | 011       | 100       | 101       | 110       | 111       |
	+-----------+           |           |           |           |           |           |           |           |
	| inst[6:5] |           |           |           |           |           |           |           | (> 32b)   |
	+===========+===========+===========+===========+===========+===========+===========+===========+===========+
	|        00 | LOAD      |           |           | MISC-MEM  | OP-IMM    | AUIPC     |           | 48b       |
	+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
	|        01 | STORE     |           |           | AMO       | OP        | LUI       |           | 64b       |
	+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
	|        10 |           |           |           |           |           |           |           | 48b       |
	+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
	|        11 | BRANCH    | JALR      |           | JAL       | SYSTEM    |           |           | >= 80b    |
	+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+

.. literalinclude:: ../../src/core/opcode_map.h
	:linenos:
	:lines: 4-15
	:caption: src/core/opcode_map.h
	:name: opcode_map.h

Instruction Types
-----------------

.. image:: tex2image/Type_of_instructions.png

.. literalinclude:: ../../src/core/inst.h
	:linenos:
	:lines: 4-49
	:caption: src/core/inst.h
	:name: inst.h

Imm_gen
-------

.. literalinclude:: ../../src/core/imm_gen.h
	:linenos:
	:lines: 4-13
	:caption: src/core/imm_gen.h
	:name: imm_gen.h

Usage:
	Assert one of `i_type`, `s_type`, `b_type`, `u_type` or `j_type` with `inst` to fetch `imm` value.
	In the same cycle, it returns `imm` value extracted from `inst`.
