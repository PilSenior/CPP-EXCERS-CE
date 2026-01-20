#include "Zombie.hpp"

Zombie* newZombie(const std::string& name) {
    // Heap'te yer ayırır ve pointer döndürür.
    // Bu zombiyi çağıran kişi (main), onu manuel olarak silmek zorundadır.
    return (new Zombie(name));
}