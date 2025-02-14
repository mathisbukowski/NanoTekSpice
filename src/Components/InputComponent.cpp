/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(std::string name) : AComponent(name, INPUT)
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    (void)pin;
    return UNDEFINED;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
}