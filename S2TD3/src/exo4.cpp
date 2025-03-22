#include "tri.hpp"
#include <iostream>

void test_search(std::vector<int> const& vec, int value) {
    int index = search(vec, value);
    std::cout << "On fait le test pour " << value << " : ";
    if (index != -1)
        std::cout << "localisé à l'indice " << index << std::endl;
    else
        std::cout << "pas trouvé" << std::endl;
}

int main() {
    std::cout << "TD 3 - Exercice 4 -> Dichotomie" << std::endl;

    std::vector<int> vec1 = {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> vec2 = {1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> vec3 = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> vec4 = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> vec5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    test_search(vec1, 8);
    test_search(vec2, 15);
    test_search(vec3, 16);
    test_search(vec4, 6);
    test_search(vec5, 10);

    return 0;
}
