#include "npi.hpp"

int main()
{


    std::cout << "TD 2 exercice 2" << std::endl;

    std::string calcul;
    std::cout << "Entre un calcul sous forme NPI : " << std::endl;
    std::getline(std::cin, calcul);

    std::vector<std::string> tokens = split_string(calcul);

    try
    {
        std::vector<Token> tokenized = tokenize(tokens);

        std::cout << "Résultat : " << npi_evaluate(tokenized) << std::endl;
    }
    catch (...)
    {
        std::cout << "Erreur" << std::endl;
    }

    return 0;
}