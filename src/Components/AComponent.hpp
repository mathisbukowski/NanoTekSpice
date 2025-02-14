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
        AComponent(std::string name, nts::IComponent::ComponentType type);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        std::string getName() const;
        void setName(std::string name);
        nts::IComponent::ComponentType getType() const;
        std::vector<std::pair<std::string, std::string>> getPins() const;
        void setPinValue(const std::string& pin, const std::string& value);
        std::string getPinValue(const std::string& pin) const;
        void setPin(const std::string& pin, const std::string& value);
        void setLink(const std::string& pin, const std::string& value);

    protected:
        std::string _name;
        const nts::IComponent::ComponentType _type;
        std::vector<std::pair<std::string, std::string>> _pins;
        std::vector<std::pair<std::string, std::string>> _links;
    };
};

#endif //NANOTEKSPICE_COMPONENT_HPP