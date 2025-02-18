/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Component.hpp
*/

#ifndef NANOTEKSPICE_COMPONENT_HPP
#define NANOTEKSPICE_COMPONENT_HPP

#include "../../include/NanoTekSpice.hpp"
#include <unordered_map>

namespace nts {
    class AComponent : public IComponent {
    public:
        AComponent(const std::string& name, ComponentType type);
        virtual ~AComponent() = default;

        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        Tristate getLink(std::size_t pin) const;
        void setPinValue(std::size_t pin, Tristate value);
        Tristate getPinValue(std::size_t pin) const;

        std::string getName() const;
        void setName(const std::string& name);
        ComponentType getType() const;

        virtual void simulate(std::size_t tick) override = 0;
        virtual Tristate compute(std::size_t pin) override = 0;
        void getInputs(size_t *input1, size_t *input2, size_t pin);

    protected:
        std::string _name;
        ComponentType _type;
        std::unordered_map<std::size_t, Tristate> _pins;
        std::unordered_map<std::size_t, std::pair<IComponent*, std::size_t>> _links;
    };
};

#endif //NANOTEKSPICE_COMPONENT_HPP