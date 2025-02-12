/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NorComponent.cpp
*/

#include "NorComponent.hpp"

nts::NorComponent::NorComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::NOR)
{
}

nts::Tristate nts::NorComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}