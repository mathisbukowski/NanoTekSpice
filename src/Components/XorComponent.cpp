/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** XorComponent.cpp
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(std::string name) : AComponent(name, XOR)
{
    _pins[1] = UNDEFINED;
    _pins[2] = UNDEFINED;
    _pins[3] = UNDEFINED;
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        Tristate a = getLink(1);
        Tristate b = getLink(2);

        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if ((a == TRUE && b == FALSE) || (a == FALSE && b == TRUE))
            return TRUE;
        return FALSE;
    }
    return UNDEFINED;
}

void nts::XorComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = computeInput(3);
}
