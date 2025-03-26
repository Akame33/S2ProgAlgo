#include "type.hpp"


int main() {
    std::cout << "TD 4 - Exercice 1 -> Vector and Algorithm" << std::endl;
    std::vector<int> vec(10);

    tableauAleatoire(vec);
    std::cout << "Voici le tableau généré aléatoirement : \n";
    afficherTableau(vec);

    int nombre;
    std::cout << "Entrez un nombre à rechercher dans le tableau : ";
    std::cin >> nombre;

    if(rechercheNombre(vec, nombre)){
        std::cout << nombre << " se trouve bel et bien dans le tableau \n";
    } else{
        std::cout << nombre << " n'est pas dans le tableau \n";
    }

    int occurences = compterOccurences(vec, nombre);

    std::cout << "Le nombre " << nombre << " est présent " << occurences << " fois dans le tableau. \n";

    trierTableau(vec);
    std::cout << "Voici le tableau trié : \n";
    afficherTableau(vec);

    int somme = sommeNombres(vec);
    std::cout << "Voici la somme de toutes les valeurs du tableau : " << somme << "\n";

    return 0;
}


