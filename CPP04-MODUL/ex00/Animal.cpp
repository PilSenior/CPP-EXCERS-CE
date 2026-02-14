/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:26:02 by chnaranj          #+#    #+#             */
/*   Updated: 2026/02/15 01:37:56 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << GREEN "Animal Default Constructor called" RESET << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << GREEN "Animal Copy Constructor called" RESET << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << GREEN "Animal Copy Assignment Operator called" RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << GREEN "Animal Destructor called" RESET << std::endl;
}

void Animal::makeSound() const
{
    std::cout << YELLOW "* Generic Animal Sound *" RESET << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
