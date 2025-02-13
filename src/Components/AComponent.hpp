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
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        static void dump();
        std::string getName() const;
        void setName(std::string name);
        nts::IComponent::ComponentType getType() const;
        std::vector<std::pair<std::string, std::string>> getPins() const;
        std::size_t getTick() const;
        void setPinValue(const std::string& pin, const std::string& value);
        std::string getPinValue(const std::string& pin) const;
        void setPin(const std::string& pin, const std::string& value);
        void setLink(const std::string& pin, const std::string& value);
        void setInput(const std::string& pin, const std::string& value);
        void setOutput(const std::string& pin, const std::string& value);
        static std::vector<std::pair<std::string, std::string>> getInput();
        static std::vector<std::pair<std::string, std::string>> getOutput();

    protected:
        std::string _name;
        const nts::IComponent::ComponentType _type;
        std::size_t _tick;
        std::vector<std::pair<std::string, std::string>> _pins;
        std::vector<std::pair<std::string, std::string>> _links;
        std::vector<std::pair<std::string, std::string>> _input;
        std::vector<std::pair<std::string, std::string>> _output;
    };
};

#endif //NANOTEKSPICE_COMPONENT_HPP