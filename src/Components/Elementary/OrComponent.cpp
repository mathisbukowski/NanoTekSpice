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
        Tristate a = this->computeInput(1);
        Tristate b = this->computeInput(2);

        if (a == UNDEFINED && b == UNDEFINED)
            return UNDEFINED;
        if ((a == UNDEFINED && b == FALSE) || (a == FALSE && b == UNDEFINED))
            return UNDEFINED;
        if ((a == UNDEFINED && b == TRUE) || (a == TRUE && b == UNDEFINED))
            return TRUE;
        if (a == TRUE || b == TRUE)
            return TRUE;
        return FALSE;
    }
    return UNDEFINED;
}
void nts::OrComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = this->computeInput(3);
}
