/*
** EPITECH PROJECT, 2025
** OOP-400
** File description:
** 02
*/

#include "Core/Core.hpp"
#include <iostream>
#include "Parser/Parser.hpp"

int main(int ac, char **av)
{
    nts::Core core;

    if (ac != 2) {
        std::cerr << "Usage: ./nanotekspice [file]" << std::endl;
        return 84;
    }
    return core.run(av[1]);
}