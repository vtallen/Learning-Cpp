#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vector1 {};
    vector<int> vector2 {};

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "Elements in vector1:" << endl;
    // Display all elements
    for (int i : vector1) {
        cout << i << endl;
    }
    cout << "vector1 size: " << vector1.size() << endl;
    cout << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "Elements in vector2:" << endl;
    // Display all elements
    for (int i : vector2) {
        cout << i << endl;
    }
    cout << "vector2 size: " << vector2.size() << endl;
    cout << endl;

    vector<vector<int>> vector_2d {};

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "Elements in vector_2d 0 (vector1)" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;

    cout << "Elements in vector_2d 1 (vector2)" << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;
    cout << "changed value 0 of vector 1 to 1000" << endl;

    cout << "Elements in vector_2d 0 (vector1)" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;


    return 0;
}
