/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NotComponent.hpp
*/

#ifndef NANOTEKSPICE_NOTCOMPONENT_HPP
#define NANOTEKSPICE_NOTCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
    public:
        NotComponent(std::string name);
        ~NotComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
};

#endif //NANOTEKSPICE_NOTCOMPONENT_HPP
