/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** ClockComponent.hpp
*/

#ifndef NANOTEKSPICE_CLOCKCOMPONENT_HPP
#define NANOTEKSPICE_CLOCKCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
    class ClockComponent : public AComponent {
    public:
        ClockComponent(std::string name);
        ~ClockComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setValue(Tristate value) override;
        void toggleState();
    private:
        Tristate _state;
        Tristate _tmpState;
    };
};

#endif //NANOTEKSPICE_CLOCKCOMPONENT_HPP