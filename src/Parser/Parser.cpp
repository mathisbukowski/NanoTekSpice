/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Parser.hpp"

#include <unordered_set>

nts::Parser::Parser()
{
    _input = std::vector<std::string>();
    _chipsets = std::vector<std::pair<std::string, std::string>>();
    _links = std::vector<std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>>();
}

nts::Parser::~Parser()
{
    _chipsets.clear();
    _links.clear();
    _input.clear();
}

void nts::Parser::parseFile(const std::string &filename)
{
    std::ifstream inputFile(filename);
    std::string line;

    if (!inputFile.is_open())
        throw ParserError("Error: file not found");
    while (std::getline(inputFile, line)) {
        line = cleanStr(line);
        if (line.size() > 0)
            _input.push_back(line);
    }
    inputFile.close();
    if (_input.size() == 0)
        throw ParserError("Error: empty file");
}

std::string nts::Parser::cleanStr(std::string str)
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

void nts::Parser::getChipsets()
{
    for (size_t i = 0; i < _input.size(); i++) {
        if (_input[i] == ".chipsets:") {
            parseChipsets(i);
            break;
        }
    }
}

void nts::Parser::parseChipsets(size_t &i)
{
    std::string name;
    std::string type;
    std::unordered_set<std::string> chipsetsName;

    i++;
    while (i < _input.size() && _input[i] != ".links:") {
        parseChipsetLine(_input[i], type, name);
        if (chipsetsName.find(name) != chipsetsName.end())
            throw ParserError("Error: duplicate chispet name");
        _chipsets.emplace_back(type, name);
        chipsetsName.insert(name);
        i++;
    }
}

void nts::Parser::parseChipsetLine(const std::string &line, std::string &type, std::string &name)
{
    size_t j = 0;
    type.clear();
    name.clear();

    while (j < line.size() && line[j] != ' ') {
        type += line[j];
        j++;
    }
    j++;
    while (j < line.size()) {
        name += line[j];
        j++;
    }
}

void nts::Parser::getLinks()
{
    for (size_t i = 0; i < _input.size(); i++) {
        if (_input[i] == ".links:") {
            parseLinks(i);
            break;
        }
    }
}

void nts::Parser::parseLinks(size_t &i)
{
    std::string comp1, comp2;
    std::size_t pin1, pin2;
    std::string name1, name2;
    size_t pos1, pos2;

    i++;
    while (i < _input.size()) {
        std::istringstream iss(_input[i]);
        if (!(iss >> comp1 >> comp2))
            throw ParserError("Error: incorrect link format");
        pos1 = comp1.find(':');
        pos2 = comp2.find(':');
        if (pos1 == std::string::npos || pos2 == std::string::npos)
            throw ParserError("Error: link format must be name:pin");
        name1 = comp1.substr(0, pos1);
        pin1 = std::stoul(comp1.substr(pos1 + 1));
        name2 = comp2.substr(0, pos2);
        pin2 = std::stoul(comp2.substr(pos2 + 1));
        _links.push_back({{name1, pin1}, {name2, pin2}});
        i++;
    }
}

int nts::Parser::findLinksInChipsets(std::pair<std::pair<std::string, unsigned long>, std::pair<std::string, unsigned long>>& link)
{
    auto &firstComponent = link.first.first;
    auto &secondComponent = link.second.first;
    bool firstComponentFound = false;
    bool secondComponentFound = false;

    for (auto &chipset : _chipsets) {
        if (chipset.second == firstComponent)
            firstComponentFound = true;
        if (chipset.second == secondComponent)
            secondComponentFound = true;
    }
    if (!firstComponentFound)
        return 84;
    if (!secondComponentFound)
        return 84;
    return 0;
}

bool nts::Parser::checkContentOfInputFile()
{
    if (_chipsets.empty())
        throw ParserError("Error: no chipsets found");
    if (_links.empty())
        throw ParserError("Error: no links found");
    for (auto &link : _links) {
        if (findLinksInChipsets(link) == 84)
            throw ParserError("Error: link not found in chipsets");
    }
    return true;
}

