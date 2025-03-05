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
        Tristate a = this->computeInput(input1);
        if (a == UNDEFINED)
            return UNDEFINED;
        return (a == TRUE) ? FALSE : TRUE;
    }
    return UNDEFINED;
}

void nts::Component4069::simulate(std::size_t tick)
{
    (void)tick;
    _pins[2] = this->computeInput(2);
    _pins[4] = this->computeInput(4);
    _pins[6] = this->computeInput(6);
    _pins[8] = this->computeInput(8);
    _pins[10] = this->computeInput(10);
    _pins[12] = this->computeInput(12);
}

