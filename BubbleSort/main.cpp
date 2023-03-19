#include <iostream>
#include <iterator>
#include <utility>

int main() {
  int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8};
  constexpr int length {static_cast<int>(std::size(array))};

  for (int startingIndex {0}; startingIndex < length - 1; ++startingIndex) {
    bool isSorted = true;

    for (int currentIndex {0}; currentIndex < length - 1; ++currentIndex) {
      if (array[currentIndex] > array[currentIndex + 1]) {
        std::swap(array[currentIndex], array[currentIndex + 1]);
        isSorted = false;
      }
    }
      for (int i {0}; i < length; ++i) {
    std::cout << array[i] << " ";
  }
    if (isSorted) {
      std::cout << "Sorted on iteration " << startingIndex + 1 << '\n';
      break;
    }
  }

  for (int i {0}; i < length; ++i) {
    std::cout << array[i] << " ";
  }
}