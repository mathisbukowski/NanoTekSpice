/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** XorComponent.hpp
*/

#ifndef NANOTEKSPICE_XORCOMPONENT_HPP
#define NANOTEKSPICE_XORCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
    public:
        XorComponent(std::string name);
        ~XorComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setValue(Tristate value) override {(void)value;};
    };
};

#endif //NANOTEKSPICE_XORCOMPONENT_HPP
