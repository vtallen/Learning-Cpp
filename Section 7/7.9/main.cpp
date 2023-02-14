#include <iostream>

int sumTo(int num) {
    int counter {};
    for (int i {1}; i <= num; ++i) {
        counter += i;
    }

    return counter;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << sumTo(5);
    return 0;
}
