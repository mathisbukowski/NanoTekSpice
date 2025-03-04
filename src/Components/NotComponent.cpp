/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(std::string name) : AComponent(name, NOT)
{
    _pins[1] = UNDEFINED;
    _pins[2] = UNDEFINED;
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 2) {
        Tristate a = getLink(1);

        if (a == TRUE)
            return FALSE;
        if (a == FALSE)
            return TRUE;
        return UNDEFINED;
    }
    return UNDEFINED;
}

void nts::NotComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[2] = computeInput(2);
}