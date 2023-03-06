#include <iostream>

template<typename T>
struct Triad {
    T t1;
    T t2;
    T t3;
};

template<typename T>
void print(Triad<T> t) {
    std::cout << "[" << t.t1 << ", " << t.t2 << ", " << t.t3 << "]";
}

template<typename T>
Triad(T, T, T) -> Triad<T>;


int main() {
    Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
    print(t2);
    return 0;
}
