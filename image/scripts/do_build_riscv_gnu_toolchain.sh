#!/bin/bash
set -ex

git -c submodule."qemu".update=none clone -b 2022.05.15 --depth=1 -j$(nproc) --recursive https://github.com/riscv/riscv-gnu-toolchain
pushd riscv-gnu-toolchain &> /dev/null
	#git submodule update --init --recursive
	mkdir build
	pushd build &> /dev/null
		../configure --prefix=/opt/riscv --with-arch=rv32ia --with-abi=ilp32
		make linux -j $(nproc)
		make newlib -j $(nproc)
	popd &> /dev/null
	mkdir riscv-binutils/build
	pushd riscv-binutils/build &> /dev/null
		../configure --prefix=/opt/riscv --target=riscv32-elflittle --enable-commonbfdlib --disable-gdb --enable-install-libbfd 
		make -j $(nproc)
		make install-bfd -j $(nproc)
		make install-opcodes -j $(nproc)
	popd &> /dev/null
popd &> /dev/null
rm -rf riscv-gnu-toolchain

