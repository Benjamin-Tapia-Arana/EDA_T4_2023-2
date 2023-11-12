#include "utils.hpp"
#include "ttTree/tt.hpp"
#include "ttTree/ttNode.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

int main() {
    for (int i = 3; i <= 6; ++i) {
        for (int j = 1; j <= 5; ++j) {
            std::string filepath = "insertions_" + std::to_string(i) + std::to_string(j) + ".txt";
            utils::createRandomFiles(i, filepath);
        }
    }
    std::cout << "\nAVL TREE\n" << std::endl;
    utils::testInsertions(0, 3);
    utils::testInsertions(0, 4);
    utils::testInsertions(0, 5);
    utils::testInsertions(0, 6);

    std::cout << "\n\nABB TREE\n" << std::endl;

    utils::testInsertions(1, 3);
    utils::testInsertions(1, 4);
    utils::testInsertions(1, 5);
    utils::testInsertions(1, 6);

    std::cout << "\n\n2-3 TREE\n" << std::endl;
    utils::testInsertions(2, 3);
    utils::testInsertions(2, 4);
    utils::testInsertions(2, 5);
    utils::testInsertions(2, 6);


    return 0;
}