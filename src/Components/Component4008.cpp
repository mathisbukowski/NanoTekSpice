/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** 4008Component.cpp
*/

#include "Component4008.hpp"
#include "AndComponent.hpp"
#include "XorComponent.hpp"
#include "OrComponent.hpp"

nts::Component4008::Component4008(std::string name) : AComponent(name, C4008)
{
    for (size_t i = 1; i <= 16; i++)
        _pins[i] = UNDEFINED;
}

nts::Tristate nts::Component4008::compute(std::size_t pin)
{
    if (pin == 14)
        return _pins[14];

    Tristate carry = getLink(9);
    Tristate result = UNDEFINED;

    if (pin == 10 || pin == 11 || pin == 12 || pin == 13) {
        std::size_t inA, inB;
        if (pin == 10) {
            inA = 7;
            inB = 6;
        }
        else if (pin == 11) {
            inA = 5;
            inB = 4;
        }
        else if (pin == 12) {
            inA = 3;
            inB = 2;
        }
        else {
            inA = 1;
            inB = 15;
        }
        Tristate a = getLink(inA);
        Tristate b = getLink(inB);
        result = static_cast<Tristate>(a ^ b ^ carry);
        Tristate newCarry = static_cast<Tristate>((a && b) || (carry && (a ^ b)));
        carry = newCarry;
    }
    if (pin == 13) {
        _pins[14] = carry;
    }
    return result;
}

void nts::Component4008::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t i = 10; i <= 13; i++)
        _pins[i] = compute(i);
}
