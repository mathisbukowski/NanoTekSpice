/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "4001Component.hpp"

nts::Component4001::Component4001(std::string name): AComponent(name, C4001)
{
    for (size_t i = 0; i < 14; i++)
        _pins[i] = UNDEFINED;
}

void nts::Component4001::getInputs(size_t *input1, size_t *input2, size_t pin)
{
    switch (pin) {
        case 3:
            *input1 = 1;
            *input2 = 2;
        break;
        case 4:
            *input1 = 5;
            *input2 = 6;
        break;
        case 10:
            *input1 = 8;
            *input2 = 9;
        break;
        case 11:
            *input1 = 12;
            *input2 = 13;
        break;
    }
}

nts::Tristate nts::Component4001::compute(std::size_t pin)
{
    std::size_t input1, input2;
    Tristate a, b;

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        getInputs(&input1, &input2, pin);
        a = getLink(input1);
        b = getLink(input2);
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == FALSE && b == FALSE)
            return TRUE;
        return FALSE;
    }
    return UNDEFINED;
}

void nts::Component4001::simulate(std::size_t tick)
{
    (void)tick;
    _pins[3] = compute(3);
    _pins[4] = compute(4);
    _pins[10] = compute(10);
    _pins[11] = compute(11);
}
