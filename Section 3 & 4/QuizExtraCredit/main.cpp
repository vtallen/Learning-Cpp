#include <iostream>

double distance_fallen(double seconds) {
    constexpr double gravity {9.8};

    return gravity * (seconds / 2);
}


int main() {
    std::cout << "Ball dropping off of a tower simulator\n";
    std::cout << "Tower Height(meters): ";
    double tower_height {};
    std::cin >> tower_height;

    bool is_falling {true};
    double seconds_elapsed {0.0};
    double current_height {};

    while (is_falling) {
        current_height = tower_height - distance_fallen(seconds_elapsed);

        if (current_height >= 0) {
            std::cout << "At " << seconds_elapsed << " seconds, the ball is at height: " << current_height << " meters\n";
            seconds_elapsed += 0.01;
        } else {
            is_falling = false;
        }
    }

    w

    return 0;
}
