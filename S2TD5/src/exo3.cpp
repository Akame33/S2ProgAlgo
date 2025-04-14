#include "hash.hpp"

int main()
{
    std::cout << "TD 5 - Exercice 3 -> Hash sur une structure" << std::endl;

    // 4
  std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int> card_counts;

    for (auto const& card : cards) {
        card_counts[card]++;
    }

    for (auto const& pair : card_counts) {
        std::cout << card_name(pair.first) << " : " << pair.second << '\n';
    }

    return 0;
}
