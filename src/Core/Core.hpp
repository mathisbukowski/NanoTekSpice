/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include "Parser/Parser.hpp"

namespace nts {
    class Core {
    public:
        class CoreError : public std::exception {
        private:
            std::string _message;
        public:
            CoreError(const std::string &message) : _message(message) {}
            const char *what() const noexcept override { return _message.c_str(); }
        };
        Core();
        ~Core();
        int run(const char *file);
        int loop();
        static void exit();
        int getAllArgs(nts::Parser parser, const std::string &file);
        void simulate();
        void process(const std::string input);

    };
}



#endif //CORE_HPP
