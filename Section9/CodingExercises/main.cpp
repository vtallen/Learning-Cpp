#include <iostream>
#include <vector>

using namespace std;

int sum_odd_numbers_till_15() {
    int sum {};
    for (int i = 1; i <= 15; i++) {
        if (i % 2 > 0) {
            sum += i;
        }
    }

    return sum;
}

int num_ints_divisible_3_or_5() {
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    int count {};
    for (auto num : vec) {
        if ((num % 3 == 0) || (num % 5 == 0)) {
            count++;
        }
    }
    return count;
}

int exercise17(vector<int> vec) {
    int result {};
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            //cout << result << " + " << i << " * " << j << endl;
            result += vec.at(i) * vec.at(j);
        }
    }



    return result;
}
int main() {
    cout << "Coding exercise 14" << endl;
    cout << "The sum of odd numbers up to 15 is " << sum_odd_numbers_till_15();

    cout << "Coding exercise 15" << endl;
    cout << "There are " << num_ints_divisible_3_or_5() << " numbers divisible by 3 or 5 in the vector" << endl;

    vector<int> test {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << exercise17(test) << endl;
    return 0;
}