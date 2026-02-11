#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath> 

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);              // Yeni: Int constructor
    Fixed(const float f);            // Yeni: Float constructor
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;       // Yeni: Float'a dönüştür
    int toInt(void) const;           // Yeni: Int'e dönüştür
};

// Sınıfın dışında: << operatör aşırı yüklemesi
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif