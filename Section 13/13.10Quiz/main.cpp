/*
 * Write a class named MyString that holds a std::string.
 * Overload operator<< to output the string. Overload operator() to return the substring that starts at the index of the first parameter
 * (as a MyString). The length of the substring should be defined by the second parameter.
 */
#include <iostream>

class MyString {
private:
    std::string m_string {};
public:
    MyString(std::string_view string) : m_string{string}{} //NOLINT

    std::string operator()(int start, int num_chars);
    friend std::ostream& operator<<(std::ostream& out, MyString myString);

    std::string_view substr(int start, int num_chars) {
        return std::string_view{m_string}.substr(start, num_chars);
    }
};

std::string MyString::operator()(int start, int num_chars) {
    return this->m_string.substr(start, num_chars);
}

std::ostream& operator<<(std::ostream &out, MyString myString) { //NOLINT
    std::cout << myString.m_string;
    return out;
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s.substr(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
