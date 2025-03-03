/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 03
*/

#include "LoggerComponent.hpp"

nts::LoggerComponent::LoggerComponent(std::string name) : AComponent(name, LOGGER)
{
    for (size_t i = 1; i < 11; i++)
        _pins[i] = UNDEFINED;
    _previousClock = UNDEFINED;
    _logFile.open("log.bin", std::ios::out);
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 10)
        return UNDEFINED;
    return getLink(pin);
}

void nts::LoggerComponent::simulate(std::size_t tick)
{
    (void)tick;
    Tristate clock = getLink(9);
    Tristate inhibit = getLink(10);

    if (inhibit == TRUE)
        return;
    if ((_previousClock == FALSE || _previousClock == UNDEFINED) && clock == TRUE) {
        unsigned char byte = 0;
        for (size_t i = 1; i < 9; i++) {
            Tristate pin = compute(i);
            byte |= pin << 1;
        }
        if (byte == UNDEFINED)
            return;
        _logFile.write(reinterpret_cast<const char*>(&byte), sizeof(unsigned char));
    }
}