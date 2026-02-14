/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:35:26 by chnaranj          #+#    #+#             */
/*   Updated: 2026/02/07 17:35:27 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- SUBJECT TEST: ARRAY OF ANIMALS ---" << std::endl;
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count / 2; i++)
        animals[i] = new Dog();

    for (int i = count / 2; i < count; i++)
        animals[i] = new Cat();

    std::cout << "--- DELETING ANIMALS ---" << std::endl;
    for (int i = 0; i < count; i++)
        delete animals[i];

    std::cout << "--- DEEP COPY TEST ---" << std::endl;

    Dog basic;
    basic.setIdea(0, "idea_original");

    {
        Dog tmp = basic;

        std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
        std::cout << "tmp   idea[0]: " << tmp.getIdea(0) << std::endl;

        tmp.setIdea(0, "idea_modificada_en_tmp");

        std::cout << "basic idea[0] after tmp change: " << basic.getIdea(0) << std::endl;
        std::cout << "tmp   idea[0] after tmp change: " << tmp.getIdea(0) << std::endl;
    }

    {
        Dog assigned;
        assigned = basic;

        std::cout << "basic    idea[0]: " << basic.getIdea(0) << std::endl;
        std::cout << "assigned idea[0]: " << assigned.getIdea(0) << std::endl;

        assigned.setIdea(0, "idea_modificada_en_assigned");

        std::cout << "basic    idea[0] after assigned change: " << basic.getIdea(0) << std::endl;
        std::cout << "assigned idea[0] after assigned change: " << assigned.getIdea(0) << std::endl;
    }

    std::cout << "--- END OF PROGRAM ---" << std::endl;
    return 0;
}
