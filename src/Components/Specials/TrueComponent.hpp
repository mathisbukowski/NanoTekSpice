/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** TrueComponent.hpp
*/

#ifndef NANOTEKSPICE_TRUECOMPONENT_HPP
#define NANOTEKSPICE_TRUECOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        TrueComponent(std::string name);
        ~TrueComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
};

#endif //NANOTEKSPICE_TRUECOMPONENT_HPP
