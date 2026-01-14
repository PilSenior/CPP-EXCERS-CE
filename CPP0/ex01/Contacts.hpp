/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:05:49 by htekdemi          #+#    #+#             */
/*   Updated: 2026/01/14 01:05:52 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTATS_HPP 
#define CONTATS_HPP

#include <iostream>
#include <string>

class Contact {
private:
std::string lastName;
std::string firstName;
std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();

    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickname(std::string str);
    void setPhoneNumber(std::string str);
    void setDarkestSecret(std::string str);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

    
};

#endif