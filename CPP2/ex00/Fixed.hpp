#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    Fixed();                            // Default Constructor
    Fixed(const Fixed &other);         // Copy Constructor
    Fixed &operator=(const Fixed &other); // Assignment Operator
    ~Fixed();                           // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif