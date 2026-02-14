/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:26:43 by chnaranj          #+#    #+#             */
/*   Updated: 2026/02/15 01:40:55 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << CYAN "Cat Default Constructor called" RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << CYAN "Cat Copy Constructor called" RESET << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << CYAN "Cat Copy Assignment Operator called" RESET << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << CYAN "Cat Destructor called" RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << CYAN "Meow! Meow!" RESET << std::endl;
}
