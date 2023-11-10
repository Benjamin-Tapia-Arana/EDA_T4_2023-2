#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Fisher-Yates para azar
void shuffle(std::vector<int>& array) {
    int n = array.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(array[i], array[j]);
    }
}

int main() {
    std::srand(std::time(0));

    // Menu para seleccionar los el valor de N
    int choice;
    do {
        std::cout << "Select the power of 10 for the number of random values:\n";
        std::cout << "1. 10^3\n";
        std::cout << "2. 10^4\n";
        std::cout << "3. 10^5\n";
        std::cout << "4. 10^6\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
    } while (choice < 1 || choice > 4);

    int numValues = std::pow(10, choice + 2);

    // vector donde guardar los numeros
    std::vector<int> values;
    for (int i = 1; i <= numValues; ++i) {
        values.push_back(i);
    }

    shuffle(values);

    //mete los numeros al txt
    std::ofstream outputFile("randomValues.txt");
    if (outputFile.is_open()) {
        for (int value : values) {
            outputFile << value << " ";
        }
        outputFile.close();
    } else {
        std::cerr << "Error\n";
    }

    return 0;
}

