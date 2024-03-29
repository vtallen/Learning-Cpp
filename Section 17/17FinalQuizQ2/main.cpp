/*
a) Write an Apple class and a Banana class that are derived from a common Fruit
class. Fruit should have two members: a name and a color.

The following program should run:
*/
#include <iostream>
#include <string>
#include <string_view>

class Fruit {
private:
  std::string m_name{};
  std::string m_color{};

public:
  Fruit(const std::string &name, const std::string &color)
      : m_name{name}, m_color{color} {}

  std::string_view getName() { return m_name; };
  std::string_view getColor() { return m_color; };
};

class Apple : public Fruit {
public:
  Apple(const std::string &color) : Fruit{"Apple", color} {}
  Apple(const std::string &name, const std::string &color)
      : Fruit{name, color} {}
};

class Banana : public Fruit {
public:
  Banana() : Fruit{"Banana", "yellow"} {};
  Banana(const std::string &name) : Fruit{name, "yellow"} {}
};

class GrannySmith : public Apple {
public:
  GrannySmith() : Apple{"Granny Smith", "green"} {}
};
int main() {
  Apple a{"red"};
  Banana b;
  GrannySmith c;

  std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
  std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

  return 0;
}