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
    class Core : public IComponent {
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
        void process(const std::string input);
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump();
        std::vector<std::pair<std::string, std::string>> getOutput();
        std::vector<std::pair<std::string, std::string>> getInput();
        std::size_t getTick() const;
        void setOutput(const std::string& pin, const std::string& value);
        void setInput(const std::string& pin, const std::string& value);

    private:
        std::vector<std::pair<std::string, std::string>> _output;
        std::vector<std::pair<std::string, std::string>> _input;
        std::size_t _tick;
        };
}



#endif //CORE_HPP
