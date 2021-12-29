#!/usr/bin/env python3

import sys
import os

def parse_hex_file(filename):
	mem_data = list()

	with open(filename) as f:
		for line in f.readlines():
			if line[0] == '@':
				continue
			mem_data.extend(line.strip().split(" "))
	return mem_data

def gen_mem_file(mem_data, mem_cnt):
	mem_prefix = "rom"
	mem_suffix = ".hex"
	mem = [open(mem_prefix + str(i) + mem_suffix, "w") for i in range(mem_cnt)]

	i = 0
	for data in mem_data:
		mem[i % mem_cnt].write(data + '\n')
		i += 1
		
	for f in mem:
		f.close()
def gen_rom_loader(mem_cnt):
	rom_loader_filename = "rom_loader.h"

	with open(rom_loader_filename, "w") as f:
		for i in range(mem_cnt):
			f.write("_readmemh(\"{}/rom{}.hex\", rom{});\n".format(str(i), os.getcwd(), str(i)))

def help(argc, argv):
	print("Usage: {} <hex_file_name> <memory_file_count>".format(argv[0][2:]))

def main(argc, argv):
	if argc != 3:
		print("not sufficent arguments")
		help(argc, argv)
		sys.exit(1)
	mem_data = parse_hex_file(argv[1])
	gen_mem_file(mem_data, int(argv[2]))
	gen_rom_loader(int(argv[2]))

if __name__ == '__main__':
	main(len(sys.argv), sys.argv)
