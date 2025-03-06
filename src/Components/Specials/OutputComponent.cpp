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
    return this->computeInput(pin);
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
}
