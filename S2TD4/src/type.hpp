#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>

// Exercice 1 - Vector and Algorithm
void tableauAleatoire (std::vector<int>& vec);
void afficherTableau(const std::vector<int>& vec);
bool rechercheNombre(const std::vector<int>& vec, int nombre);
int compterOccurences(const std::vector<int>& vec, int nombre);
void trierTableau(std::vector<int>& vec);
int sommeNombres(std::vector<int>& vec);

// Exercice 2 - String
size_t longueurMotUn(std::string const& str);
std::vector<std::string> split_string(std::string const& str);

// Exercice 3   - Palindrome
bool palindromeOuPas(const std::string& str);

// Exercice pour aller plus loin - Lambda
std::vector<int> sumCarre(std::string const& str);




