/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Parser.hpp"

Parser::Parser()
{
    _input = std::vector<std::string>();
}

Parser::~Parser()
{
    return;
}

void Parser::parseFile(const std::string &filename)
{
    std::ifstream inputFile(filename);
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file : " << filename << std::endl;
        return;
    }
    while (std::getline(inputFile, line)) {
        _input.push_back(line);
    }
    inputFile.close();
    if (_input.size() == 0)
        std::cerr << "Error: file is empty" << std::endl;
}