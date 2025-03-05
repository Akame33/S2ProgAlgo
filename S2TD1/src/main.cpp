#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    std::cout << f1;
    std::cout << " f2 = ";
    std::cout << f2;
    std::cout << std::endl;

// Exercice 2
    std::cout << "Exercice 1-2 \n";

    Fraction f3 = f1 + f2;
    std::cout << "f1 + f2 = " << f3 << std::endl;

    f3 = f1 - f2;
    std::cout << "f1 - f2 = " << f3 << std::endl;

    f3 = f1 * f2;
    std::cout << "f1 * f2 = " << f3 << std::endl;

    f3 = f1 / f2;
    std::cout << "f1 / f2 = " << f3 << std::endl;


// Exercice 3
    std::cout << "Exercice 3 \n";

    if (f1 == f2) {
        std::cout << "f1 est égal à f2" << std::endl;
    } else {
        std::cout << "f1 n'est pas égal à f2" << std::endl;
    }

    if (f1 != f2) {
        std::cout << "f1 est différent de f2" << std::endl;
    } else {
        std::cout << "f1 = f2" << std::endl;
    }


// Exercice 4
    std::cout << "Exercice 4 \n";

    if (f1 < f2) {
        std::cout << "f1 inférieur à f2" << std::endl;
    } else {
        std::cout << "f1 pas inférieur à f2" << std::endl;
    }

    if (f1 <= f2) {
        std::cout << "f1 inférieur ou égal à f2" << std::endl;
    } else {
        std::cout << "f1 supérieur à f2" << std::endl;
    }

    if (f1 > f2) {
        std::cout << "f1 supérieur à f2" << std::endl;
    } else {
        std::cout << "f1 pas supérieur à f2" << std::endl;
    }

    if (f1 >= f2) {
        std::cout << "f1 supérieur ou égal à f2" << std::endl;
    } else {
        std::cout << "f1 inférieur à f2" << std::endl;
    }

        return 0;
    }

