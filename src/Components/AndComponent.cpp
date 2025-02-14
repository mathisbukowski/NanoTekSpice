/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** AndComponent.cpp
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::AND)
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_pins[0].second == "1" && _pins[1].second == "1")
            return nts::Tristate::TRUE;
        else if (_pins[0].second == "0" || _pins[1].second == "0")
            return nts::Tristate::FALSE;
        else
            return nts::Tristate::UNDEFINED;
    }
    return nts::Tristate::UNDEFINED;
}

void nts::AndComponent::simulate(std::size_t tick)
{
    (void)tick;
}