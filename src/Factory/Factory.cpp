/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Factory.hpp"
#include <memory>
#include "NanoTekSpice.hpp"
#include "Components/4001Component.hpp"
#include "Components/AndComponent.hpp"
#include "Components/ClockComponent.hpp"
#include "Components/InputComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Components/OrComponent.hpp"
#include "Components/OutputComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"
#include "Components/XorComponent.hpp"

nts::Factory::Factory()
{
    componentMap = {
            {"and", []() { return std::make_unique<nts::AndComponent>("and"); }},
            {"clock", []() { return std::make_unique<nts::ClockComponent>("clock"); }},
            {"true", []() { return std::make_unique<nts::TrueComponent>("true"); }},
            {"false", []() { return std::make_unique<nts::FalseComponent>("false"); }},
            {"input", []() { return std::make_unique<nts::InputComponent>("input"); }},
            {"not", []() { return std::make_unique<nts::NotComponent>("not"); }},
            {"or", []() { return std::make_unique<nts::OrComponent>("or"); }},
            {"output", []() { return std::make_unique<nts::OutputComponent>("output"); }},
            {"xor", []() { return std::make_unique<nts::XorComponent>("xor"); }},
            {"4001", []() { return std::make_unique<nts::Component4001>("4001"); }}
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
