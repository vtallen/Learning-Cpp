/*
 *     In this quiz, we’re going to write a version of our basic calculator using function pointers.

1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.

Show Solution

1b) Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return an integer.

Show Solution

1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes two integer parameters and returns an integer. Use std::function, and include the appropriate header.

Show Solution

1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.

Show Solution

1e) Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs and print the result.
 */

#include <iostream>
#include <limits>

void clearBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

std::function<int(int, int)> getArithmeticFunction(char op) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide;
    }
}

int main() {
    bool is_running {true};
    while (is_running) {
        std::cout << "Number #1 >> ";
        int num1 {0};
        std::cin >> num1;
        clearBuffer();

        std::cout << "Number #2 >> ";
        int num2 {0};
        std::cin >> num2;
        clearBuffer();

        char op{};
        bool entering_operator {true};
        while (entering_operator) {
            std::cout << "Operator (+, -, *, /) >> ";
            std::cin >> op;
            clearBuffer();

            if (!(
                    (op == '+') ||
                    (op == '-') ||
                    (op == '*') ||
                    (op == '/')
                    )) {
                std::cout << "Invalid operator! Try again.\n";
            } else {
                entering_operator = false;
            }
        }

        std::function<int(int, int)> operation_func {getArithmeticFunction(op)};

        std::cout << "Result: " << operation_func(num1, num2) << '\n';

    }
    return 0;
}
