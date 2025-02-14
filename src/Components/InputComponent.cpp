/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(std::string name) : AComponent(name, INPUT)
{
    _pins[1] = UNDEFINED;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return _pins[1];
    return UNDEFINED;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::InputComponent::setPinValue(Tristate value)
{
    _pins[1] = value;
}
