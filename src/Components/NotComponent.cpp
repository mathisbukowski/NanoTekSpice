/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(std::string name) : AComponent(name, NOT)
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    (void)pin;
    return UNDEFINED;
}

void nts::NotComponent::simulate(std::size_t tick)
{
    (void)tick;
}