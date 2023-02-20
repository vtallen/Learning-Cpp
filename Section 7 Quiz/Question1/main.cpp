#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, double seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, double time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;


    constexpr double printIncrement {0.5}; // The number of seconds to bass between each call to calculateHeight

    double currentHeight {initialHeight};
    double currentSecond {printIncrement};
    while (currentHeight > 0.0) {
        currentHeight = calculateHeight(initialHeight, currentSecond);
        std::cout << "At " << currentSecond << " seconds, the ball is at height: " << currentHeight << "\n";

        currentSecond += printIncrement;
    }



    return 0;
}