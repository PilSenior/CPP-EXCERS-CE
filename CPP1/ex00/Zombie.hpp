#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;

public:
    // Constructor (Kurucu)
    Zombie(const std::string& name);

    // Destructor (Yıkıcı)
    ~Zombie();

    // Üye Fonksiyon
    void announce(void);
};

// Yardımcı fonksiyon prototipleri (Class dışındalar)
Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif
