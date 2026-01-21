#include "Zombie.hpp"

// zombieHorde: N tane Zombie içeren bir array oluşturur (Heap'te)
Zombie* zombieHorde(int N, const std::string& name) {
    // Heap'te N boyutunda Zombie dizisi ayır
    // new[] operatörü her bir Zombie için default constructor'ı çağırır
    Zombie* horde = new Zombie[N];
    
    // Her zombiye isim ata
    for (int i = 0; i < N; i++)
        horde[i].setName(name);

    // Diziyi döndür
    return horde;
}