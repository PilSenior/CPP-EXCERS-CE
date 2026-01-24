#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== Test 1: Normal Levels ===" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    harl.complain("INFO");
    std::cout << std::endl;
    
    harl.complain("WARNING");
    std::cout << std::endl;
    
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "=== Test 2: Invalid Inputs ===" << std::endl;
    
    std::cout << "Input: BURGER (geçersiz)" << std::endl;
    harl.complain("BURGER");
    std::cout << "(Hiçbir çıktı olmamalı)" << std::endl << std::endl;
    
    std::cout << "Input: \"\" (boş string)" << std::endl;
    harl.complain("");
    std::cout << "(Hiçbir çıktı olmamalı)" << std::endl << std::endl;
    
    std::cout << "Input: debug (küçük harf)" << std::endl;
    harl.complain("debug");
    std::cout << "(Hiçbir çıktı olmamalı)" << std::endl << std::endl;
    
    std::cout << "Input: DEBUG INFO (çoklu kelime)" << std::endl;
    harl.complain("DEBUG INFO");
    std::cout << "(Hiçbir çıktı olmamalı)" << std::endl << std::endl;
    
    std::cout << "Input: DeBuG (mixed case)" << std::endl;
    harl.complain("DeBuG");
    std::cout << "(Hiçbir çıktı olmamalı)" << std::endl << std::endl;

    std::cout << "=== All tests completed ===" << std::endl;

    return 0;
}
