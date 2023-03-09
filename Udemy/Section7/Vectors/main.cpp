#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> test_scores {100, 98, 89};

    int score_to_add {};
    cout << "Enter a test score to add to the vector: ";
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    for (int score : test_scores) {
        cout << score << endl;
    }

    return 0;
}
