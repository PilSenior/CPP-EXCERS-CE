#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    
    Zombie(const std::string& name);
    void announce(void);
    void setName(const std::string& name);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif