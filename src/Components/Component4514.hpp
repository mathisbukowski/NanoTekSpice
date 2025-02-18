/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef COMPONENT4514_HPP
#define COMPONENT4514_HPP

#include "AComponent.hpp"
#include <map>
#include <vector>

namespace nts
{
    class Component4514 : public AComponent
    {
    public:
        Component4514(std::string name);
        ~Component4514() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        size_t convertBytesToDecimal(std::string bytes);
    protected:
        std::map<size_t, size_t> _outputPinMap;
        std::vector<size_t> _outputPins;
    };
}



#endif //COMPONENT4514_HPP
