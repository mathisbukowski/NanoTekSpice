/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Component4514.hpp"


nts::Component4514::Component4514(std::string name) : AComponent(name, C4514)
{
    for (size_t i = 0; i < 25; i++)
        _pins[i] = UNDEFINED;
    _outputPinMap =  {
        {0, 11},
        {1, 9},
        {2, 10},
        {3, 8},
        {4, 7},
        {5, 6},
        {6, 5},
        {7, 4},
        {8, 18},
        {9, 17},
        {10, 20},
        {11, 19},
        {12, 14},
        {13, 13},
        {14, 16},
        {15, 15}
    };
    _outputPins = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};
}

size_t nts::Component4514::convertBytesToDecimal(std::string bytes)
{
    size_t decimal = 0;
    size_t base = 1;
    size_t len = bytes.length();

    for (size_t i = len - 1; i != SIZE_MAX; i--) {
        if (bytes[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

nts::Tristate nts::Component4514::compute(std::size_t pin)
{
    Tristate inhibit, strobe;
    if (pin < 1 || pin > 24 || pin == 12 || pin == 24)
        return UNDEFINED;
    if (pin == 1 || pin == 2 || pin == 3 || pin == 21 || pin == 22 || pin == 23)
        return getLink(pin);
    inhibit = getLink(23);
    if (inhibit == TRUE)
        return FALSE;
    strobe = getLink(1);
    if (strobe == TRUE)
        return _pins[pin];
    Tristate in0 = getLink(2);
    Tristate in1 = getLink(3);
    Tristate in2 = getLink(21);
    Tristate in3 = getLink(22);

    if (in0 == UNDEFINED || in1 == UNDEFINED || in2 == UNDEFINED || in3 == UNDEFINED)
        return UNDEFINED;
    std::string binary = "";
    binary += (in3 == TRUE) ? "1" : "0";
    binary += (in2 == TRUE) ? "1" : "0";
    binary += (in1 == TRUE) ? "1" : "0";
    binary += (in0 == TRUE) ? "1" : "0";

    size_t activeOutput = convertBytesToDecimal(binary);
    for (auto &[output, outputPin] : _outputPinMap) {
        if (outputPin == pin)
            return (output == activeOutput) ? TRUE : FALSE;
    }
    return UNDEFINED;
}

void nts::Component4514::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t pin : _outputPins) {
        _pins[pin] = compute(pin);
    }
}


