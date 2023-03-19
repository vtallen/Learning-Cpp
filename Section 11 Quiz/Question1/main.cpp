/*
 * Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
 * Create an enum to identify the different types of items, and an std::array to store the number of each item the player is carrying
 * (the enumerators are used as indexes of the array). The player should start with 2 health potions, 5 torches, and 10 arrows.
 * Write a function called countTotalItems() that returns how many items the player has in total.
 * Have your main() function print the output of countTotalItems() as well as the number of torches.
 */

#include <iostream>
#include <array>

enum class Items {
    HEALTH_POTION,
    TORCH,
    ARROW,
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
