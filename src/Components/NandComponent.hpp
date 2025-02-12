/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** NandComponent.hpp
*/

#ifndef NANOTEKSPICE_NANDCOMPONENT_HPP
#define NANOTEKSPICE_NANDCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class NandComponent : public AComponent {
    public:
        NandComponent(std::string name);
        ~NandComponent() = default;
    private:
        nts::Tristate compute(std::size_t pin) override;
    };
};

#endif //NANOTEKSPICE_NANDCOMPONENT_HPP
