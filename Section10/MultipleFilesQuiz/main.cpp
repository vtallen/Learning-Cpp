#include <iostream>

int getInteger();

int main()
{
    int x {getInteger()};
    int y {getInteger()};

    std::cout << x << " + " << y << " is " << x + y << std::endl;
    return 0;
}
