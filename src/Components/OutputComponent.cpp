/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OutputComponent.cpp
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::OUTPUT)
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
}