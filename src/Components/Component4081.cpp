/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Component4081.hpp"


nts::Component4081::Component4081(std::string name) : AComponent(name, C4081)
{
    for (size_t i = 0; i < 14; i++)
        _pins[i] = UNDEFINED;
}

nts::Tristate nts::Component4081::compute(std::size_t pin)
{
    std::size_t input1, input2;
    Tristate a, b;

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        getInputs(&input1, &input2, pin);
        a = getLink(input1);
        b = getLink(input2);
        if ((a == UNDEFINED && b == FALSE) || (a == FALSE && b == UNDEFINED))
            return FALSE;
        if ((a == UNDEFINED && b == TRUE) || (a == TRUE && b == UNDEFINED))
            return UNDEFINED;
        if (a == TRUE && b == TRUE)
            return TRUE;
        return FALSE;
    }
    return UNDEFINED;
}

void nts::Component4081::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = compute(3);
    _pins[4] = compute(4);
    _pins[10] = compute(10);
    _pins[11] = compute(11);
}

