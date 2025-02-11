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
        line = cleanStr(line);
        if (line.size() > 0)
            _input.push_back(line);
    }
    inputFile.close();
    if (_input.size() == 0)
        std::cerr << "Error: file is empty" << std::endl;
}

std::string Parser::cleanStr(std::string str)
{
    std::string cleanStr = "";
    bool wasSpace = false;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '#')
            break;
        if (str[i] != ' ' && str[i] != '\t') {
            cleanStr += str[i];
            wasSpace = false;
        } else if (!wasSpace) {
           cleanStr += ' ';
            wasSpace = true;
        }
    }
    if (!cleanStr.empty() && cleanStr.front() == ' ')
        cleanStr.erase(0, 1);
    if (!cleanStr.empty() && cleanStr.back() == ' ')
        cleanStr.pop_back();
    return cleanStr;
}