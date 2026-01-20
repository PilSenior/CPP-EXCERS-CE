#include "Zombie.hpp"

// Constructor: Zombi oluşturulurken ismini atar
Zombie::Zombie(const std::string& name) : _name(name) {
}

// Destructor: Zombi silindiğinde mesaj verir 
Zombie::~Zombie() {
    std::cout << _name << " destroyed." << std::endl;
}

// Announce: Kendini tanıtır
void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}