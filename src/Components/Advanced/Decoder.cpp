/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 03
*/

#include "Decoder.hpp"

#include <cmath>

nts::Decoder::Decoder(std::string name) : AComponent(name, DECODER)
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

nts::Tristate nts::Decoder::compute(std::size_t pin)
{
    Tristate inhibit, strobe;
    std::string toBinary = "";
    Tristate a, b, c, d;

    if (pin < 1 || pin > 24 || pin == 12 || pin == 24)
        return UNDEFINED;
    if (pin == 1 || pin == 2 || pin == 3 || pin == 21 || pin == 22 || pin == 23)
        return computeInput(pin);
    inhibit = computeInput(23);
    if (inhibit == TRUE)
        return FALSE;
    strobe = computeInput(1);
    if (strobe == TRUE)
        return computeInput(pin);
    a = computeInput(2);
    b = computeInput(3);
    c = computeInput(21);
    d = computeInput(22);

    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED || d == UNDEFINED)
        return UNDEFINED;
    toBinary += (a == TRUE) ? "1" : "0";
    toBinary += (b == TRUE) ? "1" : "0";
    toBinary += (c == TRUE) ? "1" : "0";
    toBinary += (d == TRUE) ? "1" : "0";

    size_t outputActive = convertByteToDecimal(toBinary);
    for (auto &[output, outputPin] : _outputPinMap)
        if (outputPin == pin)
            return (output == outputActive) ? TRUE : FALSE;
    return UNDEFINED;
}

size_t nts::Decoder::convertByteToDecimal(std::string toConvert)
{
    size_t decimal = 0;
    size_t power = 0;

    for (int i = toConvert.size() - 1; i >= 0; i--) {
        if (toConvert[i] == '1')
            decimal += std::pow(2, power);
        power++;
    }
    return decimal;
}

void nts::Decoder::simulate(std::size_t tick)
{
    (void)tick;
    for (auto outputPin : _outputPins)
        _pins[outputPin] = computeInput(outputPin);
}
