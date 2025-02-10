/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>

#include "../../include/NanoTekSpice.hpp"

class Factory {
public:
    virtual std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
    virtual ~Factory() = default;
};



#endif //FACTORY_HPP
