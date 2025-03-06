/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** FalseComponent.hpp
*/

#ifndef NANOTEKSPICE_FALSECOMPONENT_HPP
#define NANOTEKSPICE_FALSECOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
    public:
        FalseComponent(std::string name);
        ~FalseComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setValue(Tristate value) override {(void)value;};
    };
};


#endif //NANOTEKSPICE_FALSECOMPONENT_HPP
