#include <vector>
#include <algorithm>
#include <iostream>
#include "tri.hpp"


int main() {
    std::cout << "TD 3 - Exercice 2 -> Tri récursif" << std::endl;


    std::vector<int> vec = {3, 1, 5, 2, 8, 7};

    std::cout << "Tri avec Merge Sort :" << std::endl;
    merge_sort(vec);
    for (float num : vec) {
        std::cout << num << " - ";
    }
    std::cout << std::endl;

    return 0;
}