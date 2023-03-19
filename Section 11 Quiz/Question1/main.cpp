/*
 * Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
 * Create an enum to identify the different types of items, and an std::array to store the number of each item the player is carrying
 * (the enumerators are used as indexes of the array). The player should start with 2 health potions, 5 torches, and 10 arrows.
 * Write a function called countTotalItems() that returns how many items the player has in total.
 * Have your main() function print the output of countTotalItems() as well as the number of torches.
 */

#include <iostream>
#include <array>

namespace Items {
    enum Items {
        HEALTH_POTION,
        TORCH,
        ARROW,
    };
}

template<std::size_t Size>
int countTotalItems(const std::array<int, Size> &array) {
    int total_items {0};
    for (int num_items : array) {
        total_items += num_items;
    }

    return total_items;
}

int main() {
    std::array<int, 3> player_items {2, 5, 10};

    std::cout << "The player has " << countTotalItems(player_items) << " items." << '\n';
    std::cout << "The player has " << player_items[Items::TORCH] << " torches." << '\n';

    return 0;
}
