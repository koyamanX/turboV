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
        if(!j["stages"]["dispatch0"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["dispatch0"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Rn" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds0" << std::endl;
        }
        if(!j["stages"]["dispatch1"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["dispatch1"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Rn" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds1" << std::endl;
        }
        if(!j["stages"]["dispatch2"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["dispatch2"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Rn" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds2" << std::endl;
        }
        if(!j["stages"]["execute0"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["execute0"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds0" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex0" << std::endl;
        }
        if(!j["stages"]["execute1"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["execute1"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds1" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex1" << std::endl;
        }
        if(!j["stages"]["execute2"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["execute2"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ds2" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex2" << std::endl;
        }
        if(!j["stages"]["writeback0"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["writeback0"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex0" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Wb0" << std::endl;
        }
        if(!j["stages"]["writeback1"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["writeback1"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex1" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Wb1" << std::endl;
        }
        if(!j["stages"]["writeback2"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["writeback2"]["ptr"];
            std::cout << "E" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Ex2" << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Wb2" << std::endl;
        }
        if(!j["stages"]["commit0"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["commit0"]["ptr"];
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Cm0" << std::endl;
        }
        if(!j["stages"]["commit1"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["commit1"]["ptr"];
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Cm1" << std::endl;
        }
        if(!j["stages"]["rename0"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["rename0"]["ptr"];
            ptr2id[stoi(ptr, nullptr, 16)] = id++;
            std::cout << "I" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << ptr << "\t" << tid << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Rn" << std::endl;
            std::cout << "L" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 1 << "\t" << "ptr: " << j["stages"]["rename0"]["ptr"] << std::endl;
        }
        if(!j["stages"]["rename1"].is_null()) {
            std::string ptr;

            ptr = j["stages"]["rename1"]["ptr"];
            ptr2id[stoi(ptr, nullptr, 16)] = id++;
            std::cout << "I" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << ptr << "\t" << tid << std::endl;
            std::cout << "S" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 0 << "\t" << "Rn" << std::endl;
            std::cout << "L" << "\t" << ptr2id[stoi(ptr, nullptr, 16)] << "\t" << 1 << "\t" << "ptr: " << j["stages"]["rename1"]["ptr"] << std::endl;
        }
    }
    return 0;
}
