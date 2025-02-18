/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Component4011.hpp"


nts::Component4011::Component4011(std::string name): AComponent(name, C4011)
{
    for (size_t i = 0; i < 14; i++)
        _pins[i] = UNDEFINED;
}

nts::Tristate nts::Component4011::compute(std::size_t pin)
{
    std::size_t input1, input2;
    Tristate a, b;

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        getInputs(&input1, &input2, pin);
        a = getLink(input1);
        b = getLink(input2);
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE && b == TRUE)
            return FALSE;
        return TRUE;
    }
    return UNDEFINED;
}