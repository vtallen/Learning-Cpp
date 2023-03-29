
/*
 * a) Create a class called IntPair that holds two integers.
 * This class should have two member variables to hold the integers.
 * You should also create two member functions: one named “set” that will let you assign values to the integers,
 * and one named “print” that will print the values of the variables.

The following main function should execute:
 */
#include <iostream>

class IntPair {
private:
    int x {};
    int y {};

public:
    IntPair(int x, int y) {
        this->x = x;
        this-> y = y;
    }
    IntPair() {

    }

    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        std::cout << "Pair(" << x << "," << y << ")\n";
    }
};

int main()
{
    IntPair p1;
    p1.set(1, 1); // set p1 values to (1, 1)

    IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}
