#include <iostream>

void question_two() {
    char current {97};
    constexpr char end {122};

    while (current <= end) {
        std::cout << current << " ";
        current++;
    }
    std::cout << '\n';
}

void question_three() {
    int outer {5};
    while (outer > 0) {

        int inner {0};
        while (outer > inner) {
            std::cout << outer - inner << " ";
            ++inner;
        }

        std::cout << '\n';
        --outer;
    }
}

void question_four() {
    int outer {1};

    while (outer <= 5) {

        int inner {5};
        while (inner >= 1) {
            if (inner <= outer) {
                std::cout << inner << ' ';
            } else {
                std::cout << "  ";
            }
            --inner;
        }
        std::cout << '\n';
        ++outer;
    }
}

int main() {
    question_two();
    std::cout << '\n';
    question_three();
    std::cout << '\n';
    question_four();
    std::cout << '\n';


    return 0;
}
