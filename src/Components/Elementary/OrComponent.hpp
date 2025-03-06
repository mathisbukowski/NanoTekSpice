/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OrComponent.hpp
*/

#ifndef NANOTEKSPICE_ORCOMPONENT_HPP
#define NANOTEKSPICE_ORCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
    public:
        OrComponent(std::string name);
        ~OrComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setValue(Tristate value) override {(void)value;};
    };
}

#endif //NANOTEKSPICE_ORCOMPONENT_HPP
