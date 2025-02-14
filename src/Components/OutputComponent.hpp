/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OutputComponent.hpp
*/

#ifndef NANOTEKSPICE_OUTPUTCOMPONENT_HPP
#define NANOTEKSPICE_OUTPUTCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
    public:
        OutputComponent(std::string name);
        ~OutputComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
};

#endif //NANOTEKSPICE_OUTPUTCOMPONENT_HPP
