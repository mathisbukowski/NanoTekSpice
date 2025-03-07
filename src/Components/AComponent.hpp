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
#include <unordered_set>

namespace nts {
    struct pair_hash {
        // This function template generates a hash value for a pair of elements.
        // It combines the hash values of the first and second elements of the pair
        // using the bitwise XOR operator to ensure a unique hash for the pair.
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2> &pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    class AComponent : public IComponent {
    public:
        AComponent(const std::string& name, ComponentType type);
        virtual ~AComponent() = default;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void setPinValue(std::size_t pin, Tristate value);
        Tristate getPinValue(std::size_t pin) const;
        std::string getName() const;
        void setName(const std::string& name);
        ComponentType getType() const;
        Tristate computeInput(size_t pin);
        virtual void setValue(Tristate value) = 0;
        virtual void simulate(std::size_t tick) override = 0;
        virtual Tristate compute(std::size_t pin) override = 0;
        void getInputs(size_t *input1, size_t *input2, size_t pin);
        void getInput(size_t *input, size_t pin);
        std::pair<IComponent*, std::size_t> getLink(size_t pin) const;

    protected:
        std::string _name;
        ComponentType _type;
        std::unordered_map<std::size_t, Tristate> _pins;
        std::unordered_map<std::size_t, std::pair<IComponent*, std::size_t>> _links;
        std::unordered_set<std::pair<IComponent*, std::size_t>, pair_hash> _active;
        std::unordered_map<std::size_t, Tristate> _lastComputed;
    };
};

#endif //NANOTEKSPICE_COMPONENT_HPP