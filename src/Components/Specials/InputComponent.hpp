/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** InputComponent.hpp
*/

#ifndef NANOTEKSPICE_INPUTCOMPONENT_HPP
#define NANOTEKSPICE_INPUTCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class InputComponent : public AComponent {
    public:
        InputComponent(std::string name);
        ~InputComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setPinValue(Tristate value);
    };
};

#endif //NANOTEKSPICE_INPUTCOMPONENT_HPP
