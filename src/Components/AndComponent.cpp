/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** AndComponent.cpp
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent(std::string name) : AComponent(name, AND)
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_pins[0].second == "1" && _pins[1].second == "1")
            return TRUE;
        if (_pins[0].second == "0" || _pins[1].second == "0")
            return FALSE;
        return UNDEFINED;
    }
    return UNDEFINED;
}

void nts::AndComponent::simulate(std::size_t tick)
{
    (void)tick;
}