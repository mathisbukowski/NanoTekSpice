/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4081_HPP
#define COMPONENT4081_HPP
#include "../AComponent.hpp"


namespace nts {
    class Component4081 : public AComponent {
    public:
        Component4081(std::string name);
        ~Component4081() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}



#endif //COMPONENT4081_HPP
