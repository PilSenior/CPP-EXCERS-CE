/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 01:05:38 by htekdemi          #+#    #+#             */
/*   Updated: 2026/02/04 19:00:01 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int argc, char **argv) {
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; argv[i][j] != '\0'; j++)
            {
                argv[i][j] = std::toupper(argv[i][j]);
                std::cout << argv[i][j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}