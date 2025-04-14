#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <random>
#include <functional>




// Exercice 1 - Fonction de hachage
size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m);


// Exercice 2
enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

extern const std::vector<Insect> insect_values;
extern const std::unordered_map<Insect, std::string> insect_to_string;
extern const std::vector<int> expected_insect_counts;


std::vector<float> probabilities_from_count(const std::vector<int>& counts);

std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t number_of_observations,
    const std::vector<float>& insect_probabilities,
    unsigned int seed = std::random_device{}()
);

// Exercice 3

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const;
    size_t hash() const;
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t size);
std::string card_name(Card const& card);






