#include <iostream>
#include <string>
#include <string_view>
/*
Let’s implement our Fruit example that we talked about in our introduction to
inheritance. Create a Fruit base class that contains two private members: a name
(std::string), and a color (std::string). Create an Apple class that inherits
Fruit. Apple should have an additional private member: fiber (double). Create a
Banana class that also inherits Fruit. Banana has no additional members.
*/

class Fruit {
private:
  const std::string m_name{};
  const std::string m_color{};

public:
  Fruit(const std::string_view name, const std::string_view color)
      : m_name{name}, m_color{color} {}

  std::string getName() { return m_name; };
  std::string getColor() { return m_color; };

  friend std::ostream &operator<<(std::ostream &out, Fruit fruit) {
    std::cout << "Fruit(" << fruit.getName() << "," << fruit.getColor() << ")";
    return out;
  }
};

class Apple : Fruit {
private:
  const double m_fiber{};

public:
  Apple(const std::string_view name, const std::string_view color,
        const double fiber)
      : Fruit{name, color}, m_fiber{fiber} {}

  double getFiber() { return m_fiber; };

  friend std::ostream &operator<<(std::ostream &out, Apple apple) {
    std::cout << "Apple(" << apple.getName() << "," << apple.getColor() << ","
              << apple.getFiber() << ")";

    return out;
  }
};

class Banana : Fruit {
public:
  Banana(const std::string_view name, const std::string_view color)
      : Fruit{name, color} {}

  friend std::ostream &operator<<(std::ostream &out, Banana banana) {
    std::cout << "Banana(" << banana.getName() << "," << banana.getColor()
              << ")";

    return out;
  }
};

int main() {
  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}