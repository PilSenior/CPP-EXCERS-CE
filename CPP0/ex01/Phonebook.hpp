#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <Contact.hpp>

class Phonebook {
private:
    Contact contacts[8];
    int index;
    int totalSavedContacts;

public:
    Phonebook();
    void addContact();
    void searchContact();
    void displayContacts();
};

#endif