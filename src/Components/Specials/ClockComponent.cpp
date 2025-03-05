/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name) : AComponent(name, CLOCK)
{
    _pins[1] = UNDEFINED;
    _state = UNDEFINED;
}

void nts::ClockComponent::toggleState()
{
    _state = _state == TRUE ? FALSE : TRUE;
    this->setPinValue(_state);
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    return this->getPinValue(pin);
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        return;
    this->toggleState();
}

void nts::ClockComponent::setPinValue(Tristate value)
{
    _pins[1] = value;
}
