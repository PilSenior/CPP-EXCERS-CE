#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// --- Public Fonksiyon (Dispatch Logic) ---

void Harl::complain(std::string level) {
    // 1. Fonksiyon İşaretçileri Dizisi (Pointer to Member Functions)
    // Bu dizi, Harl sınıfının void dönen ve parametre almayan fonksiyonlarının adreslerini tutar.
    void (Harl::*ptrFuncs[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // 2. Seviye İsimleri Dizisi (Mapping için)
    std::string levels[] = {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };

    // 3. Döngü ile eşleşmeyi bulma
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // Eşleşme bulundu! Sihirli syntax:
            // (this->*ptrFuncs[i])();
            // this-> : Bu sınıfın örneği üzerinde çalış.
            // *ptrFuncs[i] : Dizideki adresteki fonksiyonu dereference et.
            // () : Fonksiyonu çağır.
            (this->*ptrFuncs[i])();
            return;
        }
    }
    // Opsiyonel: Eğer level bulunamazsa hiçbir şey yapmaz (Subject'te hata mesajı zorunluluğu yok).
}