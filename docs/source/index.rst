.. storm documentation master file, created by
   sphinx-quickstart on Sat Jan  8 00:20:57 2022.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to storm's documentation!
=================================

The Storm is a synthesizable open-source `RISC-V <https://riscv.org>`_ Out-of-Order core written in `NSL <http://www.overtone.co.jp/products/nsl-core/>`_ hardware description language. The goal of this document is to describe the design and implementation of the core and SoC.

Useful Links
------------
- https://github.com/koyamanX/storm.git

Quick-start
-----------

The easiest and best way to build and test storm core is to use Docker image(storm_dev).
The code below describes the ways to build and test storm core using pre-build docker image.

.. _build-and-test-steps:
.. code-block::
	:caption: Quick start

	git clone --recursive https://github.com/koyamanX/storm.git
	cd storm/image
	# Build docker image from Dockerfile, it takes a while.
	./build.sh
	cd ../
	# Run docker container
	./run.sh
	mkdir build
	cd build
	cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./
	make install
	make test

Table of Contents
-----------------
.. toctree::
   :maxdepth: 2

   storm_microarch.rst
   storm_pipeline.rst
   nsl.rst
   riscv.rst
   ifetch_unit.rst
   decode.rst
   issue.rst
   dispatch.rst
   execute.rst
   writeresult.rst
   commit.rst
