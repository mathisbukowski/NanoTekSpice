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
    _links = std::vector<std::pair<std::string, std::string>>();
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
        parseLinkLine(_input[i], type, name);
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
    std::string name;
    std::string type;
    std::unordered_set<std::string> linkNames;

    i++;
    while (i < _input.size()) {
        parseLinkLine(_input[i], type, name);
        if (linkNames.find(name) != linkNames.end())
            throw ParserError("Error: duplicate link name");
        _links.emplace_back(type, name);
        linkNames.insert(name);
        i++;
    }
}

void nts::Parser::parseLinkLine(const std::string &line, std::string &type, std::string &name)
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

int nts::Parser::separateValueFromKeyOfLinks(const std::string& link)
{
    for (size_t i = 0; i < link.size(); i++)
        if (link[i] == ':')
            return std::stoi(link.substr(i + 1));
    return 84;
}

std::string nts::Parser::getNameOfLink(std::pair<std::string, std::string> &link)
{
    std::string name;

    for (size_t i = 0; i < link.first.size(); i++)
        if (link.first[i] == ':')
            name = link.first.substr(0, i);
    return name;
}

bool nts::Parser::checkContentOfInputFile()
{
    if (_chipsets.empty())
        throw ParserError("Error: no chipsets found");
    if (_links.empty())
        throw ParserError("Error: no links found");
    for (auto &it : _links)
    {
        for (auto &it2 : _chipsets)
        {
            if (getNameOfLink(it) == it2.second)
                break;
            if (&it2 == &_chipsets.back())
                throw ParserError("Error: link to non-existing component");
        }
    }
    return true;
}

