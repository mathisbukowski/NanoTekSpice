/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4071_HPP
#define COMPONENT4071_HPP
#include "../AComponent.hpp"


namespace nts {
    class Component4071 : public AComponent {
    public:
        Component4071(std::string name);
        ~Component4071() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
};



#endif //COMPONENT4071_HPP
