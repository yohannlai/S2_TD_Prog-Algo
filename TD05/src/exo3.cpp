#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }

    // Fonction de hachage dite parfaite pour la structure Card : chaque carte (valeur + famille) est transformée en un entier unique entre 0 et 51
    // Il y a 13 valeurs (Two à Ace) par famille (Heart, Diamond, Club, Spade), soit 4 familles * 13 valeurs = 52 cartes
    // On associe un entier de 0 à 3 à chaque famille, et de 0 à 12 à chaque valeur
    // Le calcul kind * 13 + value permet donc de numéroter les cartes de façon unique et sans collision
    size_t hash() const {
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + std::to_string(card_value);
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'J';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main()
{
    std::srand(std::time(nullptr));

    std::vector<Card> cards = get_cards(100);

    std::unordered_map<Card, int> counts;

    for (const Card& card : cards)
    {
        counts[card]++;
    }

    for (const auto& pair : counts)
    {
        std::cout << card_name(pair.first) << " : " << pair.second << std::endl;
    }

    return 0;
}