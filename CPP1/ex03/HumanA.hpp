#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon; // DİKKAT: Referans (&)

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void attack();
};

#endif