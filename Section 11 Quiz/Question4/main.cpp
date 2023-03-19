/*
 * Write a function to print a C-style string character by character.
 * Use a pointer to step through each character of the string and print that character.
 * Stop when you hit the null terminator.
 * Write a main function that tests the function with the string literal “Hello, world!”.

Hint: Use the ++ operator to advance the pointer to the next character.
 */

#include <iostream>

int main() {
    char* hello {"Hello World!"};
    char* ptr {hello};

    while (*ptr != '\0') {
        std::cout << *ptr << " ";
        ++ptr;
    }
    return 0;
}
