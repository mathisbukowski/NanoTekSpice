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
    if (_pins[1] == TRUE && tick != 0)
        _pins[1] = FALSE;
    else if (_pins[1] == FALSE && tick != 0)
        _pins[1] = TRUE;
}

void nts::ClockComponent::setPinValue(Tristate value)
{
    std::cout << "Test" << std::endl;
    _pins[1] = value;
}
