/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4030_HPP
#define COMPONENT4030_HPP
#include "../AComponent.hpp"


namespace nts {

    class Component4030 : public AComponent {
    public:
        Component4030(std::string name);
        ~Component4030() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}



#endif //COMPONENT4030_HPP
