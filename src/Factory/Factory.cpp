/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Factory.hpp"

#include "Components/AndComponent.hpp"
#include "Components/ClockComponent.hpp"
#include "Components/InputComponent.hpp"
#include "Components/NandComponent.hpp"
#include "Components/NorComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Components/OrComponent.hpp"
#include "Components/OutputComponent.hpp"
#include "Components/XorComponent.hpp"

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type)
{
    if (type == "and") return std::make_unique<nts::AndComponent>("and");
    if (type == "clock") return std::make_unique<nts::ClockComponent>("clock");
    if (type == "input") return std::make_unique<nts::InputComponent>("input");
    if (type == "nand") return std::make_unique<nts::NandComponent>("nand");
    if (type == "nor") return std::make_unique<nts::NorComponent>("nor");
    if (type == "not") return std::make_unique<nts::NotComponent>("not");
    if (type == "or") return std::make_unique<nts::OrComponent>("or");
    if (type == "output") return std::make_unique<nts::OutputComponent>("output");
    if (type == "xor") return std::make_unique<nts::XorComponent>("xor");
    return nullptr;
}