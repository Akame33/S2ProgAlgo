#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include "type.hpp"


int main() {
    std::cout << "TD 4 - Exercice 3 -> Palindrome" << std::endl;

    std::string palindrome = "kayak";
    std::cout << "Est ce que " << palindrome << " est un palindrome ? " << (palindromeOuPas(palindrome) ? "oui" : "non" )<< std::endl;

    return 0;
}
