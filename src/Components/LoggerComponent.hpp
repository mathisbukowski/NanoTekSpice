/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 03
*/

#ifndef LOGGERCOMPONENT_HPP
#define LOGGERCOMPONENT_HPP

#include "AComponent.hpp"
#include <fstream>

namespace nts {
    class LoggerComponent : public AComponent {
    public:
        LoggerComponent(std::string name);
        ~LoggerComponent() = default;
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    private:
        std::ofstream _logFile;
        Tristate _previousClock;
    };
}



#endif //LOGGERCOMPONENT_HPP
