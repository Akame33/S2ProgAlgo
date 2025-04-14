#include "hash.hpp"


// Exercice 1 - Fonction de hachage

// 1
size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash {0};
    for (char c : s)
    {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash % max;
} 

// 2
size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0};
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
        hash %= max; 
    }
    return hash;
}

// 3
size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    size_t hash = 0;
    size_t power = 1; // (parce que p^0 = 1)

    for (char c : s) {
        hash = (hash + (static_cast<size_t>(c) * power) % m) % m;
        power = (power * p) % m;
    }

    return hash;

}

// Exercice 2 - Analyse du nombre d'insectes

//donné
const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

//donné
const std::unordered_map<Insect, std::string> insect_to_string {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

// donné
std::vector<int> const expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};

// 1. 
std::vector<float> probabilities_from_count(const std::vector<int>& counts) {
    float total = static_cast<float>(std::accumulate(counts.begin(), counts.end(), 0));
    std::vector<float> probabilities;
    for (int count : counts) {
        probabilities.push_back(count / total);
    }
    return probabilities;
}

// donné
std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t number_of_observations,
    const std::vector<float>& insect_probabilities,
    unsigned int seed) 
    {
    std::default_random_engine random_engine{seed};
    auto rand_insect_index = std::bind(
        std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()},
        random_engine
    );

    std::vector<std::pair<Insect, int>> observations;
    observations.reserve(number_of_observations);

    for (size_t i = 0; i < number_of_observations; ++i) {
        size_t random_insect_index = rand_insect_index();
        Insect insect = insect_values[random_insect_index];

        if (!observations.empty() && observations.back().first == insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({insect, 1});
        }
    }

    return observations;
}

// Exercice 3 - Hash sur une structure

// 1
bool Card::operator==(const Card& other) const {
    return kind == other.kind && value == other.value;
}

// 2 & 3
size_t Card::hash() const {
    return static_cast<size_t>(static_cast<int>(kind) * 13 + static_cast<int>(value));
}

std::vector<Card> get_cards(size_t size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name;
    unsigned int card_value = (static_cast<unsigned int>(card.value) + 2) % 14;

    if (card_value < 10) {
        name += '0' + std::to_string(card_value);
    } else if (card_value == 10) {
        name += "10";
    } else if (card_value == 11) {
        name += 'J';
    } else if (card_value == 12) {
        name += 'Q';
    } else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    switch (card.kind) {
        case CardKind::Heart: name += "Heart"; break;
        case CardKind::Diamond: name += "Diamond"; break;
        case CardKind::Club: name += "Club"; break;
        case CardKind::Spade: name += "Spade"; break;
    }

    return name;
}





