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
    _nextValue = FALSE;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return _pins[1];
    return UNDEFINED;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_pins[1] == UNDEFINED)
        _pins[1] = FALSE;
    _pins[1] = _nextValue;
    _nextValue = (_pins[1] == TRUE) ? FALSE : TRUE;
}
void nts::ClockComponent::setPinValue(Tristate value)
{
    _pins[1] = value;
    _nextValue = (value == TRUE) ? FALSE : TRUE;
}
