#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include "type.hpp"


int main() {
    std::cout << "TD 4 - Exercice 2 -> String" << std::endl;

    std::string phrase = "Tout pareil en fait";
    std::cout << "Longueur du premier mot de la phrase \" " << phrase << " \" : " << longueurMotUn(phrase) << "\n" << std::endl;

    std::cout << "Découpage des mots de la phrase : \n";

    std::vector<std::string> mots = split_string(phrase);
    for(const auto& mot : mots){
         std::cout << " - " << mot;

    }
    
    return 0;
}


