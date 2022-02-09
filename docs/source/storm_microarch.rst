.. index:: Storm Microarchitecture

Storm Microarchitecture
-----------------------

.. figure:: ../figures/Overview_of_storm_pipeline.png
	:scale: 50%
	:align: center
	:alt: Overview of storm pipeline

	Detailed Storm pipeline(currently LSU and Branch pipe are not shown)

Microarchitecture of storm is based on Tomasulo algorithm with speculation.
It is implemented in NSL(Next Synthsis Language). In addition to storm core,
SoC which uses storm is also implemented. The goals of this project is to implement
higher performance core compare to prior classic five stage pipelined RISC-V core `rv32x_dev <https://github.com/koyamanX/rv32x_dev>`_
and supports UNIX-like operating system.
