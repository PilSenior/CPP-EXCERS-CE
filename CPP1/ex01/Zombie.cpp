#include "Zombie.hpp"

// Default constructor: Parametresiz, isimsiz zombi oluşturur
Zombie::Zombie() {
    // İsimsiz zombi için mesaj yazdırmıyoruz
}

// Destructor: Zombi silindiğinde mesaj verir
Zombie::~Zombie() {
    std::cout << _name << " destroyed." << std::endl;
}

// setName: Zombiye isim atar
void Zombie::setName(const std::string& name) {
    this->_name = name;
}

// announce: Kendini tanıtır
void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

