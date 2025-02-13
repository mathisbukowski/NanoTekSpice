/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Core.hpp"

#include <csignal>

#include "Components/AComponent.hpp"

nts::Core::Core()
{
}

nts::Core::~Core()
{
}

int nts::Core::getAllArgs(Parser parser, const std::string &file)
{
    try
    {
        parser.parseFile(file);
        parser.getChipsets();
        parser.getLinks();
        if (!parser.checkContentOfInputFile())
            throw Parser::ParserError("Error: invalid file content");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

void nts::Core::exit()
{
    std::cout << "exit" << std::endl;
    std::exit(0);
}

void nts::Core::process(const std::string input)
{
    if (input == "simulate")
        simulate();
    else if (input == "display")
        nts::AComponent::dump();
    else
        std::cerr << "Error: invalid command" << std::endl;
}

int nts::Core::loop()
{
    std::string input;

    signal(SIGINT, [](int) { nts::Core::exit(); });
    while (true) {
        std::cout << "> ";
        if (std::getline(std::cin, input).eof())
            std::exit(0);
        if (input == "exit")
            exit();
        process(input);
    }
}


int nts::Core::run(const char *file)
{
    Parser parser;

    if (!file) {
        std::cerr << "Usage: ./nanotekspice [file]" << std::endl;
        return 84;
    }
    if (getAllArgs(parser, file) == 84)
        return 84;
    loop();
    return 0;
}