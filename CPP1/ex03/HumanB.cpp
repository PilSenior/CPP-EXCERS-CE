#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    this->_weapon = NULL; // Başlangıçta silahı yok, güvenli hale getiriyoruz.
}

HumanB::~HumanB() {
}

// Dışarıdan referans alır, ama kendi pointer'ına adresini (&) atar.
void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack() {
    // Güvenlik kontrolü: Silahı var mı?
    if (this->_weapon != NULL) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}