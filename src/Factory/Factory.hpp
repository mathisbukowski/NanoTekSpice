/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>

#include "NanoTekSpice.hpp"

class Factory {
public:
    Factory() = default;
    ~Factory() = default;
     std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
};



#endif //FACTORY_HPP
