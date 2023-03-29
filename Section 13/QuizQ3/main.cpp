/*
 * Let’s create a random monster generator. This one should be fun.

a) First, let’s create an enumeration of monster types named MonsterType.
 Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
 Add an additional max_monster_types enum so we can count how many enumerators there are.

Show Solution

b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType),
 a name (std::string), a roar (std::string), and the number of hit points (int).
 Create a Monster class that has these 4 member variables.

Show Solution

c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration. When the enum is inside the class, “MonsterType” can be renamed “Type” since the context is already Monster.

Show Solution

d) Create a constructor that allows you to initialize all of the member variables.

The following program should compile:
 */

#include <iostream>
#include "random.h"

/*
 * f) Now we can create a random monster generator.
 * Let’s consider how our monster generator will work.
 * Ideally, we’ll ask it to give us a Monster, and it will create a random one for us.
 * We don’t need more than one monster generator, and we are not maintaining any state,
 * so this is a good candidate for a namespace. Create a namespace named MonsterGenerator.
 * Create a function named generate() that returns a Monster. For now, make it return anonymous
 * Monster { Monster::Type::skeleton, "Bones", "*rattle*", 4 };
 */

class Monster {
public:
    enum Type {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES,
    };

private:
    Type m_type {};
    std::string m_name {};
    std::string m_roar {};
    int m_HP {};

public:
    Monster(Type type, std::string name, std::string roar, int HP)
    : m_type{type}, m_name{name}, m_roar{roar}, m_HP{HP} {}

    static std::string getTypeString(Type type) {
        switch (type) {
            case DRAGON:
                return "Dragon";
            case GOBLIN:
                return "Goblin";
            case OGRE:
                return "Ogre";
            case ORC:
                return "Orc";
            case SKELETON:
                return "Skeleton";
            case TROLL:
                return "Troll";
            case VAMPIRE:
                return "Vampire";
            case ZOMBIE:
                return "Zombie";
            case MAX_MONSTER_TYPES:
                return "END";
        }
    }

    void print() {
        std::cout << "The " << Monster::getTypeString(m_type) << " "
        << m_name << " says " << m_roar << " and has " << m_HP << " HP";
    }
};
/*
 * Now, MonsterGenerator needs to generate some random attributes.
 * To do that, first copy and save the “Random.h” header from lesson 7.19 --
 * Generating random numbers using Mersenne Twister to your project.

Modify the function generate() from the prior quiz to generate a random
 Monster::Type (between 0 and Monster::Type::max_monster_types-1) and a random hit points (between 1 and 100).
 This should be fairly straightforward.

Once you’ve done that, define two static fixed arrays of size 6 inside the function (named s_names and s_roars)
 and initialize them with 6 names and 6 sounds of your choice. Pick a random name and roar from these arrays.

The following program should compile:
 */
namespace MonsterGenerator {
    Monster generate() {
        const std::string s_names[] {"jimmy", "deborah", "bob", "timmy", "potato man", "ZombieMcZomFace"};
        const std::string s_roars[] {"*WOOF*", "*rattle*", "*ROOOOAR*", "*BLEHHH*", "*OOOOOOOO*", "*BOOPP*"};
        return Monster { static_cast<Monster::Type>(Random::get(0, Monster::MAX_MONSTER_TYPES - 1)),
                         s_names[Random::get(0, 5)],
                         s_roars[Random::get(0, 5)],
                         Random::get(0, 100)};
    }
}

int main()
{
    Monster m{ MonsterGenerator::generate() };
    m.print();

    return 0;
}