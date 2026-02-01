
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
private:
    int                 _Value;
    static const int    _fractionalBits = 8;

public:
    // Constructor (Kurucu)
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    // Destructor (Yıkıcı)
    ~Fixed();

    // Üye Fonksiyon
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif