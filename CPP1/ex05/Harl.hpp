#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    // Harl'ın özel fonksiyonları (Subject'ten gelen isimler)
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();

    // Tek giriş kapımız
    void complain(std::string level);
};

#endif