#include <iostream>

/*
 * A factorial of an integer N (written N!) is defined as the product (multiplication) of all the numbers between 1 and N (0! = 1).
 * Write a recursive function called factorial that returns the factorial of the input.
 * Test it with the first 7 factorials.
 */
int factorial(int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }

    return factorial(num - 1) * num;
}

/*
 * Write a recursive function that takes an integer as input and returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15).
 * Print the answer for input 93427 (which is 25). Assume the input values are positive.
 */
int digitSum(int num) {
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    return digitSum(num / 10) + (num % 10);
}

int main() {
    std::cout << "The factorials of 1-7:\n\t";
    for (int i {0}; i < 7; ++i) {
        std::cout << i + 1 << " - " << factorial(i) << '\t';
    }

    std::cout << "\n\nThe sum of the digits of numbers 1-100\n";
    for (int i {1}; i <= 100; ++i) {
        std::cout << digitSum(i);
        std::cout << '\t';
    }

    return 0;
}
