#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>

// Exercice 1 - Vector and Algorithm

void tableauAleatoire(std::vector<int> &vec)
{
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::rand() % 101;
    }
}

void afficherTableau(const std::vector<int> &vec)
{
    for (auto iterator = vec.begin(); iterator != vec.end(); ++iterator)
    {
        std::cout << *iterator << " ";
    };
    std::cout << std::endl;
}

bool rechercheNombre(const std::vector<int> &vec, int nombre)
{
    return std::find(vec.begin(), vec.end(), nombre) != vec.end();
}

int compterOccurences(const std::vector<int>& vec, int nombre){
    return std::count(vec.begin(), vec.end(), nombre);
}

void trierTableau(std::vector<int>& vec){
    std::sort(vec.begin(), vec.end());
}

int sommeNombres(std::vector<int>& vec){
    return std::accumulate(vec.begin(), vec.end(), 0);
}

// Exercice 2 - String

size_t longueurMotUn(std::string const& str){
    auto const is_space = [](char letter){ return letter == ' '; };
    auto debut = std::find_if_not(str.begin(), str.end(), is_space);
    if (debut == str.end()) return 0;

    auto fin = std::find_if(debut, str.end(), is_space);

    return std::distance(debut, fin);

}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> mots;
    auto const is_space = [](char letter){ return letter == ' '; };
    auto debut = str.begin();

    while (debut != str.end()) {
        debut = std::find_if_not(debut, str.end(), is_space);
        if (debut == str.end()) break;

        auto fin = std::find_if(debut, str.end(), is_space);

        mots.emplace_back(debut, fin);
        debut = fin;
    }
    return mots;
}

// Exercice 3 - Palindrome
bool palindromeOuPas(const std::string& str){
    return std::equal(std::begin(str), std::end(str), std::rbegin(str));
}

// Exercice pour aller plus loin - lambda
int sommeCarre(std::vector<int> const &v)
{
    return std::accumulate(v.begin(), v.end(), 0, [](int a, int b) { return a + (b * b); });
}

int paire(std::vector<int> const &v)
{
    return std::accumulate(v.begin(), v.end(), 1, 
        [](int a, int b) { return (b % 2 == 0) ? a * b : a; }
    );
}