#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Constructors & Destructor
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    // Raw bits access
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison Operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment / Decrement Operators
    Fixed &operator++(void);    // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed &operator--(void);    // Pre-decrement
    Fixed operator--(int);     // Post-decrement

    // Static member functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif