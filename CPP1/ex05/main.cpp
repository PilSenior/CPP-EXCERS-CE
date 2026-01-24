#include "Harl.hpp"

int main() {
    Harl harl;

    // Testleri sırayla yapıyoruz
    // Subject: "Create and turn in tests to show that Harl complains a lot."
    
    harl.complain("DEBUG");
    std::cout << std::endl;

    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;

    harl.complain("ERROR");
    std::cout << std::endl;

    // Geçersiz girdi testi (Hiçbir şey yazdırmamalı)
    harl.complain("BURGER"); 

    return 0;
}