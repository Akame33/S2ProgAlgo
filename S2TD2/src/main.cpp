#include "npi.hpp"

int main()
{
    std::string calcul;
    std::cout << "TD 2 exercice 1" << std::endl;
    std::cout << "Entre un calcul sous forme NPI : " << std::endl;
    std::getline(std::cin, calcul);

    std::vector<std::string> tokens = split_string(calcul);

    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            std::cout << "Nombre : " << token << std::endl;
        }
        else
        {
            std::cout << "Operateur : " << token << std::endl;
        }
    }

    try
    {
        std::cout << "Résultat : " << npi_evaluate(tokens) << std::endl;
    }
    catch (...)
    {
        std::cout << "Erreur" << std::endl;
    }

    std::cout << "TD 2 exercice 2" << std::endl;

    try
    {
        std::vector<Token> tokenized = tokenize(tokens);

        for (const Token &token : tokenized)
        {
            if (token.type == TokenType::OPERAND)
            {
                std::cout << "Nombre : " << token.value << std::endl;
            }
            else
            {
                std::cout << "Operateur : " << static_cast<int>(token.op) << std::endl;
            }
        }

        std::cout << "Résultat : " << npi_evaluate(tokenized) << std::endl;
    }
    catch (...)
    {
        std::cout << "Erreur" << std::endl;
    }

    return 0;
}