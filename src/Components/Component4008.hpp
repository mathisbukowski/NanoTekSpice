/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** 4008Component.hpp
*/

#ifndef NANOTEKSPICE_4008COMPONENT_HPP
#define NANOTEKSPICE_4008COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class Component4008 : public AComponent {
    public:
        Component4008(std::string name);
        ~Component4008() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}

#endif //NANOTEKSPICE_4008COMPONENT_HPP
