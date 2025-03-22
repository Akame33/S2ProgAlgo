#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include "ScopedTimer.hpp"
#include "tri.hpp"


int main() {
    std::vector<int> array {1, 4, 3, 2, 6, 5, 7, 8, 9};

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    std::cout << "TD 3 - Exercice 1 -> Tri itératif bubble sort" << std::endl;

    std::cout << "Tableau initial :" << std::endl;
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    bubble_sort(array);

    std::cout << "Tableau après tri à bulles (bubble sort) :" << std::endl;
    for (int num : array) std::cout << num << " - ";
    std::cout << std::endl;

    return 0;
}


