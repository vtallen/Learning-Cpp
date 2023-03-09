#include <iostream>
#include <iterator>
#include <utility>

int main() {
    int array[] {40, 59, 20,10,59,100, 4, 62, 345, 234,2,34,4,56,7,1,567,1};

    constexpr int length {static_cast<int>(std::size(array))};

    for (int startIndex {0}; startIndex < length -1; ++startIndex) {
        int smallestIndex {startIndex};

        for (int currentIndex {startIndex + 1}; currentIndex < length; ++currentIndex) {
            if (array[currentIndex] < array[smallestIndex]) {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }

    for (int i {}; i < length; ++i) {
        std::cout << array[i] << '\n';
    }
    return 0;
}
