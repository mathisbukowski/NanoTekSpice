/*
** EPITECH PROJECT, 2025
** OOP-400
** File description:
** 02
*/

#include <iostream>
#include "Parser/Parser.hpp"

int main(int ac, char **av)
{
    Parser parser;

    (void)ac;
    try
    {
        if (av[1])
        {
            parser.parseFile(av[1]);
            parser.getChipsets();
            parser.getLinks();
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    for (auto &it : parser._chipsets) {
        std::cout << it.first << " " << it.second << std::endl;
    }
    for (auto &it : parser._links) {
        std::cout << it.first << " " << it.second << std::endl;
        std::cout << "value of first pin: " << parser.separateValueFromKeyOfLinks(it.first) << std::endl;
        std::cout << "value of second pin: " << parser.separateValueFromKeyOfLinks(it.second) << std::endl;
    }
    return 0;
}