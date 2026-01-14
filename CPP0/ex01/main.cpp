#include <iostream>
#include <string>
#include "Phonebook.hpp"



int main(){

    
    Phonebook phonebook;
    std::string command;

    std::cout << "\033[31mWelcome to the Phonebook application!\033[0m" << std::endl;
    std::cout << "\033[33mAvailable commands:\nADD: You can add a new contact\nSEARCH: You can search and delete for a contacts you have\nEXIT: You can exit the application.\033[0m" << std::endl;

    while(true)
    {
        std::cout << "\033[32m> \033[0m";

        if (!std::getline(std::cin, command))
            break;
        
        if (command == ("EXIT" || "exit")) {
            break;
        }
        else if(command == ("ADD" || "add"))
            phonebook.addContact();
        
        else if(command == ("SEARCH" || "search"))
            phonebook.searchContact();
        
        else
            std::cout << "\033[31mInvalid command. Please try again.\033[0m" << std::endl;
    }
    return 0;
}