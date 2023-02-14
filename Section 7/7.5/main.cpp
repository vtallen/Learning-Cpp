#include <iostream>

double calculate(double a, double b, char operation) {
    double result {-1};

    switch (operation) {
        case '+':
            result = a + b;
            return result;
        case '-':
            result = a - b;
            return result;
        case '*':
            result = a * b;
            return result;
        case '/':
            result = a / b;
            return result;
        default:
            return result;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
