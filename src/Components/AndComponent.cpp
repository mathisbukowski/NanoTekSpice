/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** AndComponent.cpp
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent(std::string name) : AComponent(name, AND)
{
    _pins[1] = UNDEFINED;
    _pins[2] = UNDEFINED;
    _pins[3] = UNDEFINED;
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        Tristate a = _pins[1];
        Tristate b = _pins[2];

        if (a == TRUE && b == TRUE)
            return TRUE;
        if (a == FALSE || b == FALSE)
            return FALSE;
        return UNDEFINED;
    }
    return UNDEFINED;
}

void nts::AndComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = compute(3);
}