/*
** EPITECH PROJECT, 2025
** OOP-400
** File description:
** NanoTekSpice.hpp
*/

#ifndef NANOTEKSPICE_HPP
    #define NANOTEKSPICE_HPP

#include <iostream>

namespace nts {
    class Core;
    class Parser;
    class IComponent;
    class Factory;
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public:
          enum ComponentType
          {
                INPUT,
                OUTPUT,
                TRUECOMPONENT,
                FALSECOMPONENT,
                CLOCK,
                AND,
                NAND,
                NOR,
                NOT,
                OR,
                XOR,
                C4001,
                C4011,
                C4030,
                C4069,
                C4071,
                C4081,
                C4514
          };
          virtual ~IComponent() = default;
          virtual void simulate(std::size_t tick) = 0;
          virtual Tristate compute(std::size_t pin) = 0;
          virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
    };
};

#endif // NANOTEKSPICE_HPP