#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to the carpet cleaning service!" << endl;
    cout << "Small rooms: $25 | Large rooms: $35" << endl;

    cout << "How many small rooms: ";
    int num_small_rooms {};
    cin >> num_small_rooms;

    cout << "How many large rooms: ";
    int num_large_rooms {};
    cin >> num_large_rooms;

    const double small_room_price = 25.0;
    const double large_room_price = 35.0;
    const double sales_tax = 0.06;
    const int expiry_days = 30;

    double small_room_subtotal = (num_small_rooms * small_room_price);
    double large_room_subtotal = (num_large_rooms * large_room_price);
    double subtotal = small_room_subtotal + large_room_subtotal;
    double tax = sales_tax * subtotal;
    double total = tax + subtotal;

    cout << "Subtotal for small rooms: $" << small_room_subtotal << endl;
    cout << "Subtotal for large rooms: $" << large_room_subtotal << endl;
    cout << "Subtotal: $" << subtotal <<endl;
    cout << "Sales tax: $" << tax << endl;
    cout << "=====================================" << endl;
    cout << "Total: $" << total << endl;

    return 0;
}
