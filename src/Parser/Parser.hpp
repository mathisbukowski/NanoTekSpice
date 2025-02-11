/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include "NanoTekSpice.hpp"
#include <iostream>
#include <fstream>
#include <vector>

class Parser {
  public:
    Parser();
    ~Parser();
    void parseFile(const std::string &filename);
    std::string cleanStr(std::string str);
  private:
    std::vector<std::string> _input;
};



#endif //PARSER_HPP
