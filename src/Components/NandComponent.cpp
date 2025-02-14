/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NandComponent.cpp
*/

#include "NandComponent.hpp"

nts::NandComponent::NandComponent(std::string name) : AComponent(name, NAND)
{
}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    (void)pin;
    return UNDEFINED;
}

void nts::NandComponent::simulate(std::size_t tick)
{
    (void)tick;
}
