/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contats.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:19:40 by htekdemi          #+#    #+#             */
/*   Updated: 2026/01/14 05:19:41 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact() {
}

void Contact::setFirstName(std::string str) {
    this->firstName = str;
}

void Contact::setLastName(std::string str) {
    this->lastName = str;
}

void Contact::setNickname(std::string str) {
    this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
    this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
    this->darkestSecret = str;
}

// --- GETTER METODLARI (Veri Okuma) ---

std::string Contact::getFirstName() {
    return this->firstName;
}

std::string Contact::getLastName() {
    return this->lastName;
}

std::string Contact::getNickname() {
    return this->nickname;
}

std::string Contact::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() {
    return this->darkestSecret;
}