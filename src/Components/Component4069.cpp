/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Component4069.hpp"

nts::Component4069::Component4069(std::string name) : AComponent(name, C4069)
{
    for (size_t i = 0; i < 14; i++)
        _pins[i] = UNDEFINED;
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    std::size_t input1;

    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12) {
        getInput(&input1, pin);
        return getLink(input1);
    }
    return UNDEFINED;
}

void nts::Component4069::simulate(std::size_t tick)
{
    (void)tick;
    _pins[2] = compute(2);
    _pins[4] = compute(4);
    _pins[6] = compute(6);
    _pins[8] = compute(8);
    _pins[10] = compute(10);
    _pins[12] = compute(12);
}

