#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <ios>
#include <limits>

enum class Ranks {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    RANKS_MAX,
};

enum class Suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    SUITS_MAX,
};

struct Card {
    Ranks rank;
    Suits suit;
};

void printCard(Card& card) {

    switch (card.rank) {
        case Ranks::ACE: std::cout << 'A'; break;
        case Ranks::TWO: std::cout << '2'; break;
        case Ranks::THREE: std::cout << '3'; break;
        case Ranks::FOUR: std::cout << '4'; break;
        case Ranks::FIVE: std::cout << '5'; break;
        case Ranks::SIX: std::cout << '6'; break;
        case Ranks::SEVEN: std::cout << '7'; break;
        case Ranks::EIGHT: std::cout << '8'; break;
        case Ranks::NINE: std::cout << '9'; break;
        case Ranks::TEN: std::cout << 'T'; break;
        case Ranks::JACK: std::cout << 'J'; break;
        case Ranks::KING: std::cout << 'K'; break;
        case Ranks::QUEEN: std::cout << 'Q'; break;
        default: std::cout << "-";
    }

    switch (card.suit) {
        case Suits::DIAMONDS: std::cout << 'D'; break;
        case Suits::CLUBS: std::cout << 'C'; break;
        case Suits::HEARTS: std::cout << 'H'; break;
        case Suits::SPADES: std::cout << 'S'; break;
        default: std::cout << '-';
    }
}

void printDeck(std::array<Card, 52>& deck) {
    for (Card card : deck) {
        printCard(card);
        std::cout << " ";
    }
}

std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck {};

    int card_num {};
    for (int rank {0}; rank < static_cast<int>(Ranks::RANKS_MAX); ++rank) {
        for (int suit {0}; suit < static_cast<int>(Suits::SUITS_MAX); ++suit) {
            Card temp_card {static_cast<Ranks>(rank), static_cast<Suits>(suit)};

            deck[card_num] = temp_card;

            ++card_num;
        }
    }

    return deck;
}

void shuffleDeck(std::array<Card, 52>& deck) {
    static std::mt19937_64 mt{static_cast<std::mt19937_64::result_type>(std::time(nullptr))};

    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(Card& card) {
    int value {};
    switch (card.rank) {
    case Ranks::ACE:
        value = 11;
        break;
    case Ranks::TWO:
    case Ranks::THREE:
    case Ranks::FOUR:
    case Ranks::FIVE:
    case Ranks::SIX:
    case Ranks::SEVEN:
    case Ranks::EIGHT:
    case Ranks::NINE:
        value = static_cast<int>(card.rank) + 1;
        break;
    case Ranks::TEN:
    case Ranks::JACK:
    case Ranks::KING:
    case Ranks::QUEEN:
        value = 10;
    }

    return value;
}

void clearBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool exit_app {false};
void playBlackjack(std::array<Card, 52>& deck) {

    bool is_game_running {true};

    static int top_card {40};

    if ((top_card + 4) >= 51) {
        std::cout << "Reached the end of the deck, shuffling...\n";
        shuffleDeck(deck);
        top_card = 0;
    }

    int dealer_score {0};
    dealer_score += getCardValue(deck[top_card]);
    ++top_card;

    dealer_score += getCardValue(deck[top_card]);
    ++top_card;

    if (dealer_score == 21) {
        std::cout << "Dealer drew a winning start hand, restarting game" << '\n';
        is_game_running = false;
    } else if (dealer_score >= 21) {
        std::cout << "Dealer busted, restarting game" << '\n';
        is_game_running = false;
    }

    int player_score {0};
    constexpr int hit{0};
    constexpr int stand{1};

    if (is_game_running) {
        std::cout << "Starting hand: ";

        printCard(deck[top_card]);
        player_score += getCardValue(deck[top_card]);
        ++top_card;

        std::cout << " ";

        printCard(deck[top_card]);
        player_score += getCardValue(deck[top_card]);
        ++top_card;

        std::cout << " | Score: " << player_score;
        std::cout << '\n';

        std::cout << "(" << hit << ")" << " Hit | (" << stand << ") Stand" << '\n';
    }

    while (is_game_running) {
        bool player_choosing_action {true};
        int player_action{-1};
        while (player_choosing_action) {
            player_action = -1;
            std::cout << ">> ";
            std::cin >> player_action;
            clearBuffer();

            if (!((player_action == hit) || (player_action == stand) || (player_action == 3))) {
                std::cout << "That was not a valid action, try again." << '\n';
            } else {
                player_choosing_action = false;
            }
        }

        // Player turn
        if (player_action == hit) {
            std::cout << "You drew ";
            printCard(deck[top_card]);
            player_score += getCardValue(deck[top_card]);
            std::cout << " | Score: " << player_score << '\n';

            ++top_card;
            if (top_card > 50) {
                std::cout << "Reached the end of the deck, shuffling...\n";
                shuffleDeck(deck);
                top_card = 0;
            }

        } else if (player_action == stand) {
            std::cout << '\n';
            std::cout << "Dealer's score: " << dealer_score << " | Your score: " << player_score << '\n';
            if (player_score > dealer_score) {
                std::cout << "You win!\n";
            } else if (player_score == dealer_score) {
                std::cout << "It's a tie!\n";
            } else {
                std::cout << "Dealer wins!\n";
            }
            is_game_running = false;
        } else if (player_action == 3) {
            exit_app = true;
            break;
        }

        if (player_score > 21) {
            std::cout << "\nYou busted... Dealer wins!\n";
            std::cout << "Dealer's score: " << dealer_score << " | Your score: " << player_score << '\n';
            is_game_running = false;
        }

        if (is_game_running) {
            //Dealer turn
            if (dealer_score < 19) {
                dealer_score += getCardValue(deck[top_card]);
                ++top_card;
            }
            if (dealer_score > 21) {
                std::cout << "\nDealer busted!\n";
                std::cout << "Dealer's score: " << dealer_score << " | Your score: " << player_score << '\n';
            }
        }
    }
}

int main() {
    std::cout << "Type 3 to exit\n\n";
    std::array<Card, 52> deck {createDeck()};
    shuffleDeck(deck);

    while (!exit_app) {
        playBlackjack(deck);
        std::cout << '\n';
    }

    return 0;
}
