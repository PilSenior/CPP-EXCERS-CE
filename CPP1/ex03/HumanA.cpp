#include "HumanA.hpp"

// DİKKAT: Referanslar constructor gövdesinde { } atanamaz.
// ": _weapon(weapon)" şeklinde Initializer List ile atanmalıdır.
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}