/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Component.cpp
*/

#include "AComponent.hpp"

#include <utility>

nts::AComponent::AComponent(std::string name, nts::IComponent::ComponentType type) : _type(type)
{
    _name = std::move(name);
}


void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}


std::string nts::AComponent::getName() const
{
    return _name;
}

void nts::AComponent::setName(std::string name)
{
    _name = std::move(name);
}

nts::IComponent::ComponentType nts::AComponent::getType() const
{
    return _type;
}

std::vector<std::pair<std::string, std::string>> nts::AComponent::getPins() const
{
    return _pins;
}

void nts::AComponent::setPinValue(const std::string& pin, const std::string& value)
{
    for (auto &p : _pins) {
        if (p.first == pin) {
            p.second = value;
            return;
        }
    }
}

std::string nts::AComponent::getPinValue(const std::string& pin) const
{
    for (auto &p : _pins) {
        if (p.first == pin) {
            return p.second;
        }
    }
    return "";
}

void nts::AComponent::setPin(const std::string& pin, const std::string& value)
{
    _pins.emplace_back(pin, value);
}

void nts::AComponent::setLink(const std::string& pin, const std::string& value)
{
    _links.emplace_back(pin, value);
}
