/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4069_HPP
#define COMPONENT4069_HPP
#include "../AComponent.hpp"


namespace nts {
    class Component4069 : public AComponent {
    public:
        Component4069(std::string name);
        ~Component4069() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };

}


#endif //COMPONENT4069_HPP
