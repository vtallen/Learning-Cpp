#include <iostream>

using namespace std;

int main() {
    char vowels [] {'a', 'i', 'a', 'o', 'u'};
    cout << "The first vowel is " << vowels[0] << endl;
    cout << "The last vowel is " << vowels[4] << endl;

    double hi_temps [] {90.1, 89.2, 77.5, 81.6};
    cout << "The first high temp is " << hi_temps[0] << endl;

    hi_temps[0] = 100.7;


    return 0;
}
