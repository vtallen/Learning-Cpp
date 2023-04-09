#include <vector>
#include <iostream>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int aScore {};
    int bScore {};
    for (int i {0}; i < 3; ++i) {
        if (a[i] > b[i]) {
            ++aScore;
        } else {
            ++bScore;
        }
    }
    
    return vector<int>{aScore, bScore};
}

int main() {
    std::vector<int> a = compareTriplets({5, 6, 7}, {3, 6, 10});
    std::cout << a[0] << a[1];
}