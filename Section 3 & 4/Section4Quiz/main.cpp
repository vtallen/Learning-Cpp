#include <iostream>

double getValue() {
    std::cout << "Enter a double value: ";
    double value {};
    std::cin >> value;

    return value;
}

int main() {
    bool run_program {true};

    while (run_program) {
        double value_one{getValue()};
        double value_two{getValue()};

        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin >> op;

        double result{};
        switch (op) {
            case '+':
                result = value_one + value_two;
                break;
            case '-':
                result = value_one - value_two;
                break;
            case '*':
                result = value_one * value_two;
                break;
            case '/':
                result = value_one / value_two;
                break;
            default:
                std::cout << "Operator not recognized" << '\n';
        }

        std::cout << value_one << " " << op << " " << value_two << " is " << result << '\n';
        std::cout << "Do another? (Y/N): ";
        char decision{};
        std::cin >> decision;

        if (!(toupper(decision) == 'Y')) {
            run_program = false;
        }

        std::cout << '\n';
    }


    return 0;
}
