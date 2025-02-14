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
                CLOCK,
                AND,
                NAND,
                NOR,
                NOT,
                OR,
                XOR
          };
          virtual ~IComponent() = default;
          virtual void simulate(std::size_t tick) = 0;
          virtual nts::Tristate compute(std::size_t pin) = 0;
    };
};

#endif // NANOTEKSPICE_HPP