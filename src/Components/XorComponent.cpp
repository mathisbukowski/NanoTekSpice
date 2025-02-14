/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** XorComponent.cpp
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(std::string name) : AComponent(name, XOR)
{
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    (void)pin;
    return UNDEFINED;
}

void nts::XorComponent::simulate(std::size_t tick)
{
    (void)tick;
}