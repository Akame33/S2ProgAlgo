#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include "type.hpp"

int main()
{
    std::cout << "TD 4 - Exercice pour aller plus loin -> lambda" << std::endl;

    std::vector<int> vec(10);
    tableauAleatoire(vec);
    afficherTableau(vec);
    std::cout << "Tableau de nombres aleatoires :" << std::endl;
    std::cout << std::endl;

    int somme = sommeCarre(vec);
    std::cout << "Somme du carre des valeurs du tableau : " << somme << std::endl;

    int produit = paire(vec);
    std::cout << "Produit des valeurs paires du tableau : " << produit << std::endl;

    return 0;
}
