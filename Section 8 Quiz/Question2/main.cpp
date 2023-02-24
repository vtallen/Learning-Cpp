#include <iostream>

using Degrees = double;
using Radians = double;

namespace constants
{
    using PI = double;
    inline constexpr PI pi { 3.14159 };
}

double convertToRadians(Degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    radians = degrees;
    return 0;
}