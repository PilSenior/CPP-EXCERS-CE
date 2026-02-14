#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << RED "--- SUBJECT TESTS ---" RESET<< std::endl;
    const Animal* cls = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << BLUE << i->getType() << " " RESET << std::endl;
    
    i->makeSound();
    j->makeSound();
    cls->makeSound();

    delete i;
    delete j;
    delete cls;

    std::cout << RED "\n--- WRONG ANIMAL TESTS ---" RESET<< std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); 
    wrongMeta->makeSound();

    delete wrongCat;
    delete wrongMeta;

    return 0;
}
