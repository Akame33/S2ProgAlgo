#include "hash.hpp"

int main()
{
    std::cout << "TD 5 - Exercice 2 -> Analyse du nombre d'insectes" << std::endl;

    std::cout << std::fixed << std::setprecision(3);

    std::vector<float> expected_probabilities = probabilities_from_count(expected_insect_counts);

    // 2
    auto observations = get_insect_observations(10000, expected_probabilities, 42);
    std::unordered_map<Insect, int> observed_counts;
    for (auto const &obs : observations)
    {
        observed_counts[obs.first] += obs.second;
    }

    // 3
    std::vector<int> observed_counts_vector;
    for (auto insect : insect_values)
    {
        observed_counts_vector.push_back(observed_counts[insect]);
    }

    std::vector<float> observed_probabilities = probabilities_from_count(observed_counts_vector);

    // 4
    std::cout << "Probabilities of observed insects vs expected probabilities\n";
    for (size_t i = 0; i < insect_values.size(); ++i)
    {
        float observed = observed_probabilities[i];
        float expected = expected_probabilities[i];
        bool ok = std::abs(observed - expected) <= 0.01f;
        auto it = insect_to_string.find(insect_values[i]);
        std::cout << it->second << " : " << observed << " vs " << expected << " " << (ok ? "OK" : "BAD") << '\n';


        return 0;
    }
}
