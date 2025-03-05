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
        Tristate a = this->computeInput(1);
        Tristate b = this->computeInput(2);

        if (a == UNDEFINED && b == UNDEFINED)
            return UNDEFINED;
        if ((a == UNDEFINED && b == FALSE) || (a == FALSE && b == UNDEFINED))
            return FALSE;
        if ((a == UNDEFINED && b == TRUE) || (a == TRUE && b == UNDEFINED))
            return UNDEFINED;
        if (a == TRUE && b == TRUE)
            return TRUE;
        return FALSE;
    }
    return UNDEFINED;
}

void nts::AndComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = this->computeInput(3);
}