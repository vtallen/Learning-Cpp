#include <iostream>
#include <vector>

class Point {
private:
    int m_x{};
    int m_y{};

public:
    Point(int x, int y)
            : m_x{x}, m_y{y} {

    }

    friend std::ostream &operator<<(std::ostream &out, const Point &p) {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }
};

class Shape {
public:
    virtual std::ostream &print(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, Shape &shape) {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
    Point m_vertexOne;
    Point m_vertexTwo;
    Point m_vertexThree;
public:
    Triangle(Point vertexOne, Point vertexTwo, Point vertexThree) : m_vertexOne{vertexOne}, m_vertexTwo{vertexTwo},
                                                                    m_vertexThree{vertexOne} {}

    std::ostream &print(std::ostream &out) const override {
        out << "Triangle(" << m_vertexOne << ", " << m_vertexTwo << ", " << m_vertexThree << ")";
        return out;
    }
};

class Circle : public Shape {
private:
    Point m_center;
    int m_radius;

public:
    Circle(Point center, int radius) : m_center{center}, m_radius{radius} {}

    std::ostream &print(std::ostream &out) const override {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
        return out;
    }

    int getRadius() const { return m_radius; }
};

int getLargestRadius(std::vector<Shape *> shapes) {
    int largestRadius{};
    for (Shape *shape: shapes) {
        Circle *circle{dynamic_cast<Circle *>(shape)};
        if (circle) {
            if (circle->getRadius() > largestRadius) largestRadius = circle->getRadius();
        }
    }
    return largestRadius;
}

int main() {
    std::vector<Shape *> v{
            new Circle{Point{1, 2}, 7},
            new Triangle{Point{1, 2}, Point{3, 4}, Point{5, 6}},
            new Circle{Point{7, 8}, 3}
    };

    // print each shape in vector v on its own line here
    for (Shape *shape: v) {
        if (shape) std::cout << *shape << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (Shape *shape: v) {
        delete shape;
    }

    return 0;
}
