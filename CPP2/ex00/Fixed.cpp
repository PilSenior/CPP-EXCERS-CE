#include "Fixed.hpp"

// Default Constructor: Değeri 0 ile başlatır.
Fixed::Fixed() : _Value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Destructor: Nesne yok edildiğinde çağrılır.
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy Constructor: Mevcut bir nesneden yeni bir tane oluşturur.
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Atama operatörünü çağırarak kod tekrarını önleriz.
}

// Copy Assignment Operator: '=' kullanıldığında çağrılır.
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Kendi kendine atama kontrolü
        this->_Value = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_Value;
}

void Fixed::setRawBits(int const raw) {
    this->_Value = raw;
}