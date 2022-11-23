#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <iostream>

using nlohmann::json;

int main(int argc, char **argv) {
    while(!std::cin.eof()) {
        json j;
        std::cin >> j >> std::ws;

        if(!j["stages"]["commit0"].is_null() && !j["stages"]["commit0"]["killed"].is_null()) {
            std::string ptr;

            std::cout << j["stages"]["commit0"]["pc"].get<std::string>() << ":" << j["stages"]["commit0"]["inst"].get<std::string>() << std::endl;
        }
        if(!j["stages"]["commit1"].is_null() && !j["stages"]["commit0"]["killed"].is_null() && !j["stages"]["commit1"]["killed"].is_null()) {
            std::string ptr;

            std::cout << j["stages"]["commit1"]["pc"].get<std::string>() << ":" << j["stages"]["commit1"]["inst"].get<std::string>() << std::endl;
        }
    }
    return 0;
}
