/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OutputComponent.cpp
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(std::string name) : AComponent(name, OUTPUT)
{
    _pins[1] = UNDEFINED;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return getLink(1);
    return UNDEFINED;
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[1] = computeInput(1);
}