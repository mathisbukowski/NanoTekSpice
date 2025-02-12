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
    private:
        nts::Tristate compute(std::size_t pin) override;
    };
};

#endif //NANOTEKSPICE_OUTPUTCOMPONENT_HPP
