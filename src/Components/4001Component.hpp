/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef C4001_HPP
#define C4001_HPP
#include "AComponent.hpp"

namespace nts {
    class Component4001 : public AComponent {
    public:
        Component4001(std::string name);
        ~Component4001() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void getInputs(size_t *input1, size_t *input2, size_t pin);
    };
}



#endif //C4001_HPP
