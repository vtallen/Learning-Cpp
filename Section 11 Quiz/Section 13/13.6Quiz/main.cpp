/*
 * Write a class named RGBA that contains 4 member variables of type std::uint8_t named m_red,
 * m_green, m_blue, and m_alpha (#include cstdint to access type std::uint8_t).
 * Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.
 * Create a constructor that uses a member initializer list that allows the user to initialize values
 * for m_red, m_blue, m_green, and m_alpha. Include a print() function that outputs the value of the member variables.
 */
#include <iostream>
#include <stdint.h>

class RGBA {
private:
    std::uint8_t m_red {};
    std::uint8_t m_blue {};
    std::uint8_t m_green {};
    std::uint8_t m_alpha {};

public:
    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255)
    : m_red {red}, m_green{green}, m_blue{blue}, m_alpha{alpha} {

    }

    void print() {
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << '\n';
    }
};


int main()
{
    RGBA teal{ 0, 127, 127 };
    teal.print();

    return 0;
}