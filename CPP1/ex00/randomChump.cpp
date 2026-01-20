#include "Zombie.hpp"

void randomChump(const std::string& name) {
    // Stack'te oluşturulur (new yok).
    Zombie z(name);
    
    // Kendini duyurur
    z.announce();

    // Fonksiyon biterken 'z' otomatik olarak yok edilir (Scope biter).
}