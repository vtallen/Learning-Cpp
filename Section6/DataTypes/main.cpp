#include <iostream>

using namespace std;

int main() {
    // Character type
    char middleInitial = 'T';
    cout << "My middle initial is " << middleInitial << endl;

    // Integer Types
    unsigned short int exam_score {55};
    cout << "My exam score was " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented << " countries represented in my meeting" << endl;

    long people_in_florida {20610000};
    cout << "There are about " << people_in_florida << " people in florida" << endl;

    long people_on_earth {7'600'000'000};
    cout << "There are about " << people_on_earth << " people on earth" << endl;

    long long distance_to_alpha_centauri {9'461'000'000'000};
    cout << "The distance to centauri is " << distance_to_alpha_centauri << " kilometers." << endl;

    // Floating point types
    float car_payment {401.23};
    cout << 'My car payment is ' << car_payment << endl;

    double pi {3.14159};
    cout << 'PI is ' << pi << endl;

    long double large_amount {2.7e100};
    cout << large_amount << " is a very big number" << endl;

    // Boolean type
    bool game_over {false};
    cout << "The value of game_over is" << game_over << endl;

    return 0;
}
