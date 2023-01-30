#include <iostream>

using namespace std;

int main() {

    char letter_grade {};

    cout << "Enter the letter grade you expect on the exam:";
    cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A':
            cout << "You need a 90 or above" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80-89" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need a 70-79" << endl;
            break;
        case 'd':
        case 'D':
            cout << "You need a 60-69" << endl;
            break;
        case 'f':
        case 'F': {
            char confirm {};
            cout << "Are you sure? (Y/N):";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cout << "Okay, I guess you didn't study" << endl;
            } else if (confirm == 'n' || confirm == 'N') {
                cout << "Good, go study" << endl;
            } else {
                cout << "Illegal Choice" << endl;
            }
            break;
        }
        default:
            cout << "Sorry, not a valid grade" << endl;
    }

    cout << endl;
    return 0;
}
