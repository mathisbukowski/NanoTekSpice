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
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
}

void nts::LoggerComponent::simulate(std::size_t tick)
{
}