/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::TrueComponent::TrueComponent(std::string name) : AComponent(name, TRUECOMPONENT)
{
    _pins[1] = TRUE;
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    return this->getPinValue(pin);
}

void nts::TrueComponent::simulate(std::size_t tick)
{
    (void)tick;
}
