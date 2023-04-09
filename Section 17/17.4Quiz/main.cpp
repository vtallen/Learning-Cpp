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
  std::string m_name{};
  std::string m_color{};

public:
  Fruit(const std::string &name, const std::string &color)
      : m_name{name}, m_color{color} {}

  // std::string getName() { return m_name; };
  const std::string &getName() const { return m_name; };

  const std::string &getColor() const { return m_color; };

  friend std::ostream &operator<<(std::ostream &out, Fruit fruit) {
    std::cout << "Fruit(" << fruit.getName() << "," << fruit.getColor() << ")";
    return out;
  }
};

class Apple : Fruit {
private:
  const double m_fiber{};

public:
  Apple(const std::string &name, const std::string &color, const double fiber)
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
  Banana(const std::string &name, const std::string &color)
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

  Banana b2{"TEST", "TEST"};
  {
    std::string test{"Macintosh"};
    b2 = Banana{test, ""};
  }

  std::cout << b2;

  // std::cout << b.getName();

  return 0;
}