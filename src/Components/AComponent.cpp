/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Component.cpp
*/

#include "AComponent.hpp"

#include <utility>

nts::AComponent::AComponent(const std::string& name, ComponentType type)
{
    _name = name;
    _type = type;
    for (std::size_t i = 1; i <= _pins.size(); i++)
        _pins[i] = UNDEFINED;
}

void nts::AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    _links[pin] = {&other, otherPin};
}

void nts::AComponent::setPinValue(std::size_t pin, Tristate value)
{
    _pins[pin] = value;
}

nts::Tristate nts::AComponent::getPinValue(std::size_t pin) const
{
    return _pins.at(pin);
}

std::string nts::AComponent::getName() const
{
    return _name;
}

nts::IComponent::ComponentType nts::AComponent::getType() const
{
    return _type;
}

void nts::AComponent::setName(const std::string& name)
{
    _name = name;
}
