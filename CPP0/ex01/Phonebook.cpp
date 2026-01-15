#include <iostream>
#include "Phonebook.hpp"
#include <iomanip> // std::setw için (tablo hizalama)


Phonebook::Phonebook(){
    this->totalSavedContacts = 0;
    std::cout << "Phonebook created!" << std::endl;
}


int checkınput(std::string str){

    int len = 0;
    len = str.length();
    int checkAlph = 0;
    int checkDigit = 0;
        for(size_t i = 0; i < str.length(); i++){
            if((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))
                checkAlph++;
            else if((str[i] <= '9' && str[i] >= '0'))
                checkDigit++;
        }
    if(checkAlph == len)
        return 1;
    if(checkDigit == len)
        return -1;

    return 0;
}

void Phonebook::addContact(){
    std::string str;

    int pos = this->totalSavedContacts % 8;

    str = "";
    while(str == "")
    {
        while(true) {
             std::cout << "Enter First Name: ";
            std::getline(std::cin, str);
            if (str.empty() || !checkınput(str))
            {
                 std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
                continue;
            }
            else
                break;
        }
    }
    this->contacts[pos].setFirstName(str);
    str = "";
    while(str == "")
    {
        while(true) {
             std::cout << "Enter Last Name: ";
            std::getline(std::cin, str);
            if (str.empty() || !checkınput(str))
            {
                 std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
                continue;
            }
            else
                break;
        }
    }
    this->contacts[pos].setLastName(str);
    str= "";
    while(str == "")
    {
        while(true) {
            std::cout << "Enter Nickname: ";
            std::getline(std::cin, str);
            if (str.empty() || !checkınput(str))
            {
                 std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
                continue;
            }
            else
                break;
        }
    }
    this->contacts[pos].setNickname(str);
    str = "";
    while(str == "")
    {
        while(true) {
             std::cout << "Enter Phone Number: ";
            std::getline(std::cin, str);
            if (str.empty() || checkınput(str) != -1)
            {
                std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
                continue;
            }
            else
                break;
        }
    }
    this->contacts[pos].setPhoneNumber(str);
    str = "";
    while(str == "")
    {
        while(true) {
            std::cout << "Enter Darkest Secret: ";
            std::getline(std::cin, str);
            if (str.empty() || !checkınput(str))
            {
                 std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
                continue;
            }
            else
                break;
        }
    }
    this->contacts[pos].setDarkestSecret(str);
    this->totalSavedContacts++;
    std::cout << "Contact added successfully!" << std::endl;

}

std::string formatTable(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::searchContact(){

    std::cout << "\033[35m|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    int full = this->totalSavedContacts;
    if(full > 8)
        full = 8;
    int i = 0;
    while(i < full)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << formatTable(this->contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << formatTable(this->contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << formatTable(this->contacts[i].getNickname());
        std::cout << "|" << std::endl;
        i++;
        std::cout << "|----------|----------|----------|----------|\033[0m" << std::endl;
    }

    std::string inputText;
    std::cout << "Please enter the chosen contact index: ";
    if(!std::getline(std::cin, inputText))
        return;
    if(inputText.length() == 1 && isdigit(inputText[0]))
    {
            int i = inputText[0] - '0';
        if (i >= 0 && i < full)
        {
            std::cout << "First Name: " << this->contacts[i].getFirstName() << std::endl;
            std::cout << "Last Name: " << this->contacts[i].getLastName() << std::endl;
            std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
            std::cout << "Phone: " << this->contacts[i].getPhoneNumber() << std::endl;
            std::cout << "Secret: " << this->contacts[i].getDarkestSecret() << std::endl;
        }
        else
            std::cout << "Invalid index. Please try again." << std::endl;
    }
    else
        std::cout << "Invalid input. Please enter a number." << std::endl;
       
}
