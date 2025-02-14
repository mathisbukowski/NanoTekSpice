/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Component.hpp
*/

#ifndef NANOTEKSPICE_COMPONENT_HPP
#define NANOTEKSPICE_COMPONENT_HPP

#include "../../include/NanoTekSpice.hpp"
#include <vector>

namespace nts {
    class AComponent : public IComponent {
    public:
        AComponent(std::string name, ComponentType type);
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
        std::string getName() const;
        void setName(std::string name);
        ComponentType getType() const;
        std::vector<std::pair<std::string, std::string>> getPins() const;
        void setPinValue(const std::string& pin, const std::string& value);
        std::string getPinValue(const std::string& pin) const;
        void setPin(const std::string& pin, const std::string& value);
        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;

    protected:
        std::string _name;
        const ComponentType _type;
        std::vector<std::pair<std::string, std::string>> _pins;
        std::vector<std::pair<std::string, std::string>> _links;
    };
};

#endif //NANOTEKSPICE_COMPONENT_HPP