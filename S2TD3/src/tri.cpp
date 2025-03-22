#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

// Exercice 1 - Tri itératif

void bubble_sort(std::vector<int> & vec){
    for (size_t i = 0; i < vec.size(); ++i)
    {
        for (size_t j = 0; j < vec.size() - 1; ++j)
        {
            if (vec[j] > vec[j + 1]){
                std::swap(vec[j], vec [j + 1]);
            }
        }
    }
}

// Exercice 2 -> Tri récursif merge sort

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right) {
    std::vector<int> left_side(vec.begin() + left, vec.begin() + middle + 1); // sous vecteur entre le début et le milieu compris 
    std::vector<int> right_side(vec.begin() + middle + 1, vec.begin() + right + 1);  // sous vecteur entre le milieu + 1 et la fin compris 

    size_t i = 0, j = 0, a = left; // les indices

    while (i < left_side.size() && j < right_side.size()) { // pour traiter tous les éléments du tableau
        if (left_side[i] <= right_side[j]) { // on compare les valeurs et on met dans k la plus petite valeur
            vec[a++] = left_side[i++];
        } else {
            vec[a++] = right_side[j++];
        }
    }

    while (i < left_side.size()) {
        vec[a++] = left_side[i++];
    }

    while (j < right_side.size()) {
        vec[a++] = right_side[j++];
    }
}

void merge_sort(std::vector<int> &vec, size_t left, size_t right) { // fonction pour implémenter le tri
    if (left >= right) { // pour dire que si le tableau contient un élément ou moins, il est déjà trié donc c'est bon
        return;
    }

    size_t middle = (left + right) / 2; // permet de calculer le middle du tableau
    merge_sort(vec, left, middle); // on applique merge_sort au coté gauche du tableau
    merge_sort(vec, middle + 1, right); // on applique merge_sort au coté droit du tableau
    merge_sort_merge(vec, left, middle, right); // on fusionne tout
}

void merge_sort(std::vector<int> &vec) {
    if (!vec.empty()) {
        merge_sort(vec, 0, vec.size() - 1);
    }
}


// Exercice 3 

std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

// Exercice 4
int search(std::vector<int> const& vec, int value) {
    size_t left = 0;
    size_t right = vec.size() - 1;

    while (left <= right) {
        size_t middle = left + (right - left) / 2;

        if (vec[middle] == value) {
            return middle; 
        }
        else if (vec[middle] < value) {
            left = middle + 1; 
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}
