/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** AndComponent.hpp
*/

#ifndef NANOTEKSPICE_ANDCOMPONENT_HPP
#define NANOTEKSPICE_ANDCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
    public:
        AndComponent(std::string name);
        ~AndComponent() = default;
    private:
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
};

#endif //NANOTEKSPICE_ANDCOMPONENT_HPP
