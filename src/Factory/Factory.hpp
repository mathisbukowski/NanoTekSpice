/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>
#include <map>
#include <functional>
#include "NanoTekSpice.hpp"

class Factory {
public:
    Factory();
    ~Factory() = default;
     std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

private:
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> componentMap;
};



#endif //FACTORY_HPP
