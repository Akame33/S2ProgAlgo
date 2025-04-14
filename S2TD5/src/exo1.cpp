#include "hash.hpp"


int main() {
    std::cout << "TD 5 - Exercice 1 -> Fonction de hachage" << std::endl;

std::vector<std::string> strings {"IMAC", "MICA", "CIMA"};
    size_t p = 31;
    size_t m = 1000000009;

    for (std::string const& s : strings)
    {
        size_t hash1 = folding_string_hash(s, 100);
        size_t hash2 = folding_string_ordered_hash(s, 100);
        size_t hash3 = polynomial_rolling_hash(s, p, m);



        std::cout << " Hash plié : " << hash1 << "\n"
                  << " Hash ordonné plié : " << hash2 << "\n"
                  << " Hash polynomial rolling hash : " << hash3;


    return 0;
}

}

