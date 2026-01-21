#include "Zombie.hpp"

#define NUM_ZOMBIES 5

int main() {
    std::cout << "--- Creating a horde of " << NUM_ZOMBIES << " zombies ---" << std::endl;
    
    // Heap'te N zombi oluştur
    Zombie* horde = zombieHorde(NUM_ZOMBIES, "HordeZombie");
    
    std::cout << "\n--- All zombies announce themselves ---" << std::endl;
    // Tüm zombileri announce ettir
    for (int i = 0; i < NUM_ZOMBIES; i++) {
        horde[i].announce();
    }

    std::cout << "\n--- Deleting the horde... ---" << std::endl;
    // ÖNEMLI: delete[] kullanılmalı (array için)
    // Bu, her bir Zombie için destructor'ı çağırır
    delete[] horde;

    return 0;
}