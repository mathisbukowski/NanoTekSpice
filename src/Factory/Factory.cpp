/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Factory.hpp"
#include <memory>
#include "../../include/NanoTekSpice.hpp"
#include "../Components/Gates/Component4001.hpp"
#include "../Components/Gates/Component4011.hpp"
#include "../Components/Elementary/AndComponent.hpp"
#include "../Components/Specials/ClockComponent.hpp"
#include "../Components/Gates/Component4030.hpp"
#include "../Components/Gates/Component4069.hpp"
#include "../Components/Gates/Component4071.hpp"
#include "../Components/Gates/Component4081.hpp"
#include "../Components/Specials/InputComponent.hpp"
#include "../Components/Elementary/NotComponent.hpp"
#include "../Components/Elementary/OrComponent.hpp"
#include "../Components/Specials/OutputComponent.hpp"
#include "../Components/Specials/TrueComponent.hpp"
#include "../Components/Specials/FalseComponent.hpp"
#include "../Components/Elementary/XorComponent.hpp"

nts::Factory::Factory()
{
    componentMap = {
            {"and", []() { return std::make_unique<AndComponent>("and"); }},
            {"clock", []() { return std::make_unique<ClockComponent>("clock"); }},
            {"true", []() { return std::make_unique<TrueComponent>("true"); }},
            {"false", []() { return std::make_unique<FalseComponent>("false"); }},
            {"input", []() { return std::make_unique<InputComponent>("input"); }},
            {"not", []() { return std::make_unique<NotComponent>("not"); }},
            {"or", []() { return std::make_unique<OrComponent>("or"); }},
            {"output", []() { return std::make_unique<OutputComponent>("output"); }},
            {"xor", []() { return std::make_unique<XorComponent>("xor"); }},
            {"4001", []() { return std::make_unique<Component4001>("4001"); }},
            {"4011", [](){ return std::make_unique<Component4011>("4011"); }},
            {"4030", [](){ return std::make_unique<Component4030>("4030"); }},
            {"4069", [](){ return std::make_unique<Component4069>("4069"); }},
            {"4071", [](){ return std::make_unique<Component4071>("4071"); }},
            {"4081", [](){ return std::make_unique<Component4081>("4081"); }},
    };
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    auto it = componentMap.find(type);
    if (it != componentMap.end()) {
        return it->second();
    }
    return nullptr;
}
