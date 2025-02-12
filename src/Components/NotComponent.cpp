/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::NOT)
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}