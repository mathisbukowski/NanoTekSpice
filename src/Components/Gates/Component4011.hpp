/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4011_HPP
#define COMPONENT4011_HPP

#include "../../../include/NanoTekSpice.hpp"
#include "../AComponent.hpp"

namespace nts {
    class Component4011 : public AComponent {
    public:
        Component4011(std::string name);
        ~Component4011() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setValue(Tristate value) override {(void)value;};
 };
};




#endif //COMPONENT4011_HPP
