#include <iostream>

void swap(int& a, int& b) {
    int temp {a};
    a = b;
    b = temp;
}

int main() {
    int a {69};
    int b {420};

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    swap(a, b);
    std::cout << "============" << '\n';

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';


    return 0;
}
