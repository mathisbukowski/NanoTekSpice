/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <map>
#include <memory>

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
        int getAllArgs(Parser *parser, const std::string &file);
        void process(std::string input);
        void dump();
        void simulate();
        std::size_t getTick() const;
        void addComponents(Parser *parser);
        void addLinks(Parser *parser);
        void editValueViaInput(const std::string &input);
        void loopEmulate();
        std::map<std::string, Tristate> getOutputs();
        std::map<std::string, Tristate> getInputs();
        std::string valueToString(Tristate &value);

    private:
        std::size_t _tick;
        std::map<std::string, std::unique_ptr<IComponent>> _components;
        };
}



#endif //CORE_HPP
