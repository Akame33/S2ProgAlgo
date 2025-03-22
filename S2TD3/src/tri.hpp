#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>

// Exercice 1
bool is_sorted(std::vector<int> const& vec);
void bubble_sort(std::vector<int> & vec);

// Exercice 2
void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> &vec, size_t left, size_t right);
void merge_sort(std::vector<int> &vec);


// Exercice 3
std::vector<int> generate_random_vector(size_t const size, int const max = 100);

// Exercice 4
int search(std::vector<int> const& vec, int value);
