/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** OutputComponent.cpp
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(std::string name) : AComponent(name, OUTPUT)
{
    _pins[1] = UNDEFINED;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        if (_links.find(1) != _links.end())
            return _links[1].first->compute(_links[1].second);
        return UNDEFINED;
    }
    return UNDEFINED;
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[1] = compute(1);
}