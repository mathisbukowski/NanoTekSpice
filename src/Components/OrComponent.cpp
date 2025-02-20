/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OrComponent.cpp
*/

#include "OrComponent.hpp"

nts::OrComponent::OrComponent(std::string name) : AComponent(name, OR)
{
    _pins[1] = UNDEFINED;
    _pins[2] = UNDEFINED;
    _pins[3] = UNDEFINED;
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        Tristate a = getLink(1);
        Tristate b = getLink(2);

        if (a == TRUE || b == TRUE)
            return TRUE;
        if (a == FALSE && b == FALSE)
            return FALSE;
        return UNDEFINED;
    }
    return UNDEFINED;
}
void nts::OrComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = compute(3);
}
