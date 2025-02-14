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
#include <sstream>
#include <algorithm>

namespace nts {
    class Parser {
    public:
        class ParserError : public std::exception {
        private:
            std::string _message;
        public:
            ParserError(const std::string &message) : _message(message) {}
            const char *what() const noexcept override { return _message.c_str(); }
        };

        std::vector<std::pair<std::string, std::string>> _chipsets;
        std::vector<std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>> _links;
        Parser();
        ~Parser();
        void parseFile(const std::string &filename);
        std::string cleanStr(std::string str);
        void getChipsets();
        void parseChipsets(size_t &i);
        void parseChipsetLine(const std::string &line, std::string &type, std::string &name);
        void getLinks();
        void parseLinkLine(const std::string &line, std::string &type, std::string &name);
        void parseLinks(size_t &i);
        int findLinksInChipsets(
            std::pair<std::pair<std::string, unsigned long>, std::pair<std::string, unsigned long>>& link);
        int separateValueFromKeyOfLinks(const std::string &link);
        std::string getNameOfLink(std::pair<std::string, std::string> &link);
        bool checkContentOfInputFile();

    private:
        std::vector<std::string> _input;
    };
}

#endif //PARSER_HPP
