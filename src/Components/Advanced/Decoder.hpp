/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 03
*/

#ifndef DECODER_HPP
#define DECODER_HPP
#include "Components/AComponent.hpp"
#include <map>
#include <vector>


namespace nts {
    class Decoder : public AComponent {
    public:
        Decoder(std::string name);
        ~Decoder() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    protected:
        size_t convertByteToDecimal(std::string toConvert);
        std::map<size_t, size_t> _outputPinMap;
        std::vector<size_t> _outputPins;
    };
};



#endif //DECODER_HPP
