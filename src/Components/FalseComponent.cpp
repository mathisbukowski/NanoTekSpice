/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** FalseComponent.cpp
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent(std::string name) : AComponent(name, FALSECOMPONENT)
{
    _pins[1] = FALSE;
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return _pins[1];
    return UNDEFINED;
}

void nts::FalseComponent::simulate(std::size_t tick)
{
    (void)tick;
}