/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name) : AComponent(name, CLOCK)
{
    _pins[1] = {};
    _state = UNDEFINED;
    _tmpState = UNDEFINED;
}

void nts::ClockComponent::toggleState()
{
    _state = _tmpState;
    if (_state == UNDEFINED)
        return;
    _tmpState = _state == TRUE ? FALSE : TRUE;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return UNDEFINED;
    return _state;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    this->toggleState();
}

void nts::ClockComponent::setValue(Tristate value)
{
    _tmpState = value;
}
