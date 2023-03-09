#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

void print_numbers(vector<int> numbers) {
    if (numbers.size() == 0) {
        cout << ">> The list has no numbers" << endl;
        return;
    }

    cout << ">> ";
    for (int i = 0; i < numbers.size(); i++) {
        if (i < numbers.size() - 1) {
            cout << numbers.at(i) << ", ";
        } else {
            cout << numbers.at(i);
        }
    }
    cout << endl;
}

void add_number(vector<int> &vect) {
    int number {};
    cout << "Enter an int >>";
    cin >> number;

    if (!count(vect.begin(), vect.end(), number)) {
        vect.push_back(number);
    } else {
        cout << ">> Number already exists in the vector" << endl;
    }
}

double get_mean(vector<int> numbers) {
    double mean {};
    if (numbers.size() > 0) {
        int sum{reduce(numbers.begin(), numbers.end())};
        mean = sum / numbers.size();
    } else {
        mean = -1;
    }

    return mean;
}


int main() {
    bool is_running {true};
    vector<int> numbers {};

    menu();
    while (is_running) {
        char menu_selection {};
        cout << ">>";
        cin >> menu_selection;

        menu_selection = toupper(menu_selection);

        switch (menu_selection) {
            case 'P':
                print_numbers(numbers);
                
                break;
            case 'A':
                add_number(numbers);
                
                break;
            case 'M':
                cout << "Mean >> " << get_mean(numbers) << endl;
                
                break;
            case 'S':
                if (!numbers.empty()) {
                    cout << "Smallest number >> " << *min_element(numbers.begin(), numbers.end()) << endl;
                } else {
                    cout << ">> The list is empty" << endl;
                }
                
                break;
            case 'L':
                if (!numbers.empty()) {
                    cout << "Largest number >> " << *max_element(numbers.begin(), numbers.end()) << endl;
                } else {
                    cout << ">> The list is empty" << endl;
                }
                
                break;
            case 'Q':
                is_running = false;
                break;
            default:
                cout << "Option not found, try again." << endl;
        }
    }


    return 0;
}
