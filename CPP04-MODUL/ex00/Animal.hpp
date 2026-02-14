/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:26:12 by chnaranj          #+#    #+#             */
/*   Updated: 2026/02/15 01:29:08 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

# define RESET          "\033[0m"
# define RED            "\033[31m"             
# define GREEN          "\033[32m"              
# define YELLOW         "\033[33m"             
# define BLUE           "\033[34m"             
# define MAGENTA        "\033[35m"              
# define CYAN           "\033[36m"              
# define WHITE          "\033[37m"              

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif
