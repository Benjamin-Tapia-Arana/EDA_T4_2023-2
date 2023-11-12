#include "ttTree/tt.hpp"
#include "ttTree/ttNode.hpp"
#include "abbTree/abb.hpp"
#include "abbTree/abbNode.hpp"
#include "avlTree/avl.hpp"
#include "avlTree/avlNode.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace utils {

void shuffle(std::vector<int>& array) {
    int n = array.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(array[i], array[j]);
    }
}

double getMedia(const std::vector<double>& nums) {
    double sum = 0.0;
    for (const auto& num : nums) sum += num;
    return sum / nums.size();
}
double standardDeviation(const std::vector<double>& nums) {
    double media = getMedia(nums);
    double sum = 0.0;
    for (const auto& num : nums) sum += std::pow(num - media, 2);
    double variance = sum / nums.size();
    double stdDev = std::sqrt(variance);

    return stdDev;
}

void createRandomFiles(int choice, const std::string& filename) {
    std::srand(std::time(0));

    int numValues = std::pow(10, choice);

    std::vector<int> values;
    for (int i = 1; i <= numValues; ++i) values.push_back(i);

    shuffle(values);

    std::string directory = "../insertions";
    if (!fs::exists(directory)) fs::create_directory(directory);
    std::string filepath = directory + "/" + filename;

    std::ofstream outputFile(filepath);
    if (outputFile.is_open()) {
        for (int value : values) outputFile << value << " ";
        outputFile.close();
    }
    else std::cerr << "Error al abrir el archivo\n";
}

double testInsertions_final(std::string filepath, int choice, int treeChoice, int iterations = 1) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "The file could not be found based on the path:" << filepath << std::endl;
        return -1;
    }

    std::vector<int> numbers;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iter(line);
        int number;
        while (iter >> number) {numbers.push_back(number);}
    }

    file.close();

    double defDuration = 0.0;

    if (treeChoice == 0) {
        trees::AVL tree;
        auto start = std::chrono::high_resolution_clock::now();
        for (int num : numbers) {tree.insert(num);}
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        defDuration = duration.count();
    }
    else if (treeChoice == 1) {
        trees::ABB tree;
        auto start = std::chrono::high_resolution_clock::now();
        for (int num : numbers) {tree.insert(num);}
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        defDuration = duration.count();
    }
    else if (treeChoice == 2) {
        trees::TT tree;
        auto start = std::chrono::high_resolution_clock::now();
        for (int num : numbers) {tree.insert(num);}
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        defDuration = duration.count();
    }

    return defDuration;
}

void testInsertions(int treeChoice, int choice) {
    std::vector<double> timers;

    for (int j = 1; j <= 5; ++j) {
        std::string filepath = "../insertions/insertions_" + std::to_string(choice) + std::to_string(j) + ".txt";
        timers.push_back(testInsertions_final(filepath, choice, treeChoice, j));
    }

    std::cout << "      |  Tiempos    : " << timers[0] << ", " << timers[1] << ", " << timers[2] << ", " << timers[3] << ", " << timers[4] << std::endl;
    std::cout << "N^" << choice << "   |  Media      : " << getMedia(timers) << std::endl;
    std::cout << "      |  Desv. Est. : " << standardDeviation(timers) << std::endl << std::endl;
}

}
