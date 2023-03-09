#include <iostream>


void one() {
    std::cout << "Hi Frank!";
}

void two() {
    int x = 3;
    std::cout << "Sally has " << x << " dogs.";
}

void three() {
    int m {};
    int d {};
    int y {};

    std::cin >> m;
    std::cin >> d;
    std::cin >> y;
}

int main() {
    std::cout << "Exercise One" << std::endl;
    one();
    std::cout << std::endl;

    std::cout << "Exercise Two" << std::endl;
    two();
    std::cout << std::endl;

    std::cout << "Exercise Three" << std::endl;
    three();
    std::cout << std::endl;

    return 0;
}


