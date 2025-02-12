/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NorComponent.hpp
*/

#ifndef NANOTEKSPICE_NORCOMPONENT_HPP
#define NANOTEKSPICE_NORCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class NorComponent : public AComponent {
    public:
        NorComponent(std::string name);
        ~NorComponent() = default;
    private:
        nts::Tristate compute(std::size_t pin) override;
    };
};

#endif //NANOTEKSPICE_NORCOMPONENT_HPP
