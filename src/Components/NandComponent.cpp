/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NandComponent.cpp
*/

#include "NandComponent.hpp"

nts::NandComponent::NandComponent(std::string name) : AComponent(name, nts::IComponent::ComponentType::NAND)
{
}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}