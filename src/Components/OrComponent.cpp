/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OrComponent.cpp
*/

#include "OrComponent.hpp"

nts::OrComponent::OrComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::OR)
{
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}