#include <iostream>

class FixedPoint2 {
private:
    bool m_is_negative {};
    std::int16_t m_whole_number {};
    std::int8_t m_decimal {};

public:
    FixedPoint2() = delete;

    FixedPoint2(std::int16_t whole_number, std::int8_t decimal):
    m_whole_number{static_cast<std::int16_t>(abs(whole_number))},
    m_decimal{static_cast<std::int8_t>(abs(decimal))},
    m_is_negative{((whole_number < 0) || (decimal < 0))}{
        assert(!(decimal < -99) && "decimal cannot be less than 99");
        assert(!(decimal > 99) && "decimal cannot be greater than 99");
    }

    explicit FixedPoint2(const double num) {
        assert((num <= 32768) && (num >= -32768) && "given double will not fit into an std::int16_t");

    }

    explicit operator double() const{
        return static_cast<double>(((m_is_negative) ? -1 : 1) * (m_whole_number + (m_decimal * 0.01)));
    }

    friend std::ostream& operator<<(std::ostream& out, FixedPoint2 fixedPoint2) {
        std::cout << static_cast<double>(fixedPoint2);

        return out;
    }

};


int main()
{
    FixedPoint2 a{ 34, 56 };
    std::cout << a << '\n';

    FixedPoint2 b{ -2, 8 };
    std::cout << b << '\n';

    FixedPoint2 c{ 2, -8 };
    std::cout << c << '\n';

    FixedPoint2 d{ -2, -8 };
    std::cout << d << '\n';

    FixedPoint2 e{ 0, -5 };
    std::cout << e << '\n';

    std::cout << static_cast<double>(e) << '\n';

    double test = 10.09;
    int test1 = test;
    double test3 = test-test1;
    std::cout << test3 << '\n';
    int8_t test4 = test3 * 100;
    std::cout << static_cast<int>(test4);

    return 0;
}
