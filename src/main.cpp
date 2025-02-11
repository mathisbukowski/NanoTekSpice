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
    parser.parseFile(av[1]);
    return 0;
}