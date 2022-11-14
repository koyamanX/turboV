#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <iostream>

using nlohmann::json;

int main(int argc, char **argv) {
	std::cout << "Kanata\t0004" << std::endl;
	std::cout << "C=\t1" << std::endl;
	uint64_t id = 0;
	uint64_t ptr2id[16] = {0};
	uint64_t tid = 0;

    while(!std::cin.eof()) {
		json j;
		std::cin >> j >> std::ws;

		std::cout << "C\t1" << std::endl;
		if(!j["stages"]["rename0"].is_null()) {
			std::string ptr;

			ptr = j["stages"]["rename0"]["ptr"];
			ptr2id[stoi(ptr)] = id++;
			std::cout << "I" << "\t" << ptr2id[stoi(ptr)] << "\t" << ptr << "\t" << tid << std::endl;
			std::cout << "S" << "\t" << ptr2id[stoi(ptr)] << "\t" << 0 << "\t" << "Rn" << std::endl;
		}
		if(!j["stages"]["rename1"].is_null()) {
			std::string ptr;

			ptr = j["stages"]["rename1"]["ptr"];
			ptr2id[stoi(ptr)] = id++;
			std::cout << "I" << "\t" << ptr2id[stoi(ptr)] << "\t" << ptr << "\t" << tid << std::endl;
			std::cout << "S" << "\t" << ptr2id[stoi(ptr)] << "\t" << 0 << "\t" << "Rn" << std::endl;
		}
    }

    return 0;
}
