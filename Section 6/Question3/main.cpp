#include <iostream>

bool passOrFail() {
    static int numRun {0};

    ++numRun;
    if (numRun <= 3) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

    return 0;
}