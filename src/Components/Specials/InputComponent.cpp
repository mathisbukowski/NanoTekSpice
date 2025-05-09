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
    return this->getPinValue(pin);
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::InputComponent::setValue(Tristate value)
{
    _pins[1] = value;
}
