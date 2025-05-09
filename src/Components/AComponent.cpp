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

std::pair<nts::IComponent*, std::size_t> nts::AComponent::getLink(size_t pin) const
{
    return _links.at(pin);
}

nts::Tristate nts::AComponent::computeInput(size_t pin)
{
    if (!_links.contains(pin))
        return UNDEFINED;
    auto [output, outputPin] = this->getLink(pin);

    std::pair current = {output, outputPin};
    if (_active.find(current) != _active.end())
        return _lastComputed[pin];
    _active.insert(current);
    if (!output || !outputPin) {
        _active.erase(current);
        return UNDEFINED;
    }
    Tristate result = output->compute(outputPin);
    _lastComputed[pin] = result;
    _active.erase(current);
    return result;
}

void nts::AComponent::getInputs(size_t *input1, size_t *input2, size_t pin)
{
    switch (pin) {
    case 3:
        *input1 = 1;
        *input2 = 2;
        break;
    case 4:
        *input1 = 5;
        *input2 = 6;
        break;
    case 10:
        *input1 = 8;
        *input2 = 9;
        break;
    case 11:
        *input1 = 12;
        *input2 = 13;
        break;
    }
}

void nts::AComponent::getInput(size_t* input, size_t pin)
{
    switch (pin) {
        case 2:
            *input = 1;
            break;
        case 4:
            *input = 3;
            break;
        case 6:
            *input = 5;
            break;
        case 8:
            *input = 9;
            break;
        case 10:
            *input = 11;
            break;
        case 12:
            *input = 13;
            break;
    }
}