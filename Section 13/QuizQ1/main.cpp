/*
 * a) Write a class named Point2d.
 * Point2d should contain two member variables of type double: m_x, and m_y,
 * both defaulted to 0.0. Provide a constructor and a print function.
 */

#include <iostream>
#include <cmath>

class Point2d {
private:
    double m_x {0.0};
    double m_y{0.0};

public:
    Point2d() = default;
    Point2d(double x, double y) : m_x{x}, m_y{y} {}

    friend double distanceTo(Point2d& p1, Point2d& p2);

    void print() const {
        std::cout << "(" << m_x << ", " << m_y << ")" << '\n';
    }

    /*
     * b) Now add a member function named distanceTo that takes another Point2d as a parameter,
     * and calculates the distance between them. Given two points (x1, y1) and (x2, y2),
     * the distance between them can be calculated as std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)).
     * The std::sqrt function lives in header cmath.
     */

//    double distanceTo(const Point2d& point) const {
//        return sqrt((this->m_x - point.m_x) * (this->m_x - point.m_x) + (this->m_y - point.m_y) * (this->m_y - point.m_y)) ;
//    }

};

double distanceTo(Point2d &p1, Point2d &p2) {
    return sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y)) ;
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceTo(first, second) << '\n';

    return 0;
}
