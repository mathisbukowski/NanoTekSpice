/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::CLOCK)
{
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
}