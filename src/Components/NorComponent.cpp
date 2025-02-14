/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NorComponent.cpp
*/

#include "NorComponent.hpp"

nts::NorComponent::NorComponent(std::string name) : AComponent(name, NOR)
{
}

nts::Tristate nts::NorComponent::compute(std::size_t pin)
{
    (void)pin;
    return UNDEFINED;
}

void nts::NorComponent::simulate(std::size_t tick)
{
    (void)tick;
}
