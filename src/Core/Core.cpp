/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** 02
*/

#include "Core.hpp"

#include <csignal>
#include <memory>

#include "Components/AComponent.hpp"
#include "Factory/Factory.hpp"

nts::Core::Core() : _tick(0)
{
}

nts::Core::~Core() = default;

int nts::Core::getAllArgs(Parser *parser, const std::string &file)
{
    try
    {
        parser->parseFile(file);
        parser->getChipsets();
        parser->getLinks();
        if (!parser->checkContentOfInputFile())
            throw Parser::ParserError("Error: invalid file content");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

void nts::Core::exit()
{
    std::cout << "exit" << std::endl;
    std::exit(0);
}

void nts::Core::process(const std::string input)
{
    if (input == "display")
        dump();
    else
        std::cerr << "Error: invalid command" << std::endl;
}

void nts::Core::add_components(std::vector<std::pair<std::string, std::string>>& chipsets)
{
    Factory factory;
    for (auto &chipset : chipsets) {
        std::unique_ptr<nts::IComponent> component = factory.createComponent(chipset.first);
        if (component) {
            AComponent *comp = dynamic_cast<AComponent *>(component.get());
            comp->setName(chipset.second);
            _components.insert(std::make_pair(chipset.second, std::move(component)));
        }
    }
    for (auto &chipset :  chipsets) {
        std::cout << "coucou" << std::endl;
        if (chipset.first == "input") {
            _input.emplace_back(chipset.second, "0");
        }
        if (chipset.first == "output") {
            _output.emplace_back(chipset.second, "0");

        }
    }
}


int nts::Core::loop()
{
    std::string input;


    signal(SIGINT, [](int) { nts::Core::exit(); });
    while (true) {
        std::cout << "> ";
        if (std::getline(std::cin, input).eof())
            std::exit(0);
        if (input == "exit")
            exit();
        process(input);
    }
}


int nts::Core::run(const char *file)
{
    Parser *parser = new Parser();

    if (!file) {
        std::cerr << "Usage: ./nanotekspice [file]" << std::endl;
        return 84;
    }
    if (getAllArgs(parser, file) == 84)
        return 84;
    add_components(parser->_chipsets);
    loop();
    return 0;
}

std::vector<std::pair<std::string, std::string>> nts::Core::getInput()
{
    return _input;
}

std::vector<std::pair<std::string, std::string>> nts::Core::getOutput()
{
    return _output;
}

void nts::Core::dump()
{
    std::vector<std::pair<std::string, std::string>> input = getInput();
    std::vector<std::pair<std::string, std::string>> output = getOutput();

    std::cout << "tick: " << getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &p : input) {
        std::cout <<  p.first << ": " << p.second << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &p : output) {
        std::cout <<  p.first << ": " << p.second << std::endl;
    }
}

std::size_t nts::Core::getTick() const
{
    return _tick;
}

void nts::Core::setInput(const std::string& pin, const std::string& value)
{
    _input.emplace_back(pin, value);
}

void nts::Core::setOutput(const std::string& pin, const std::string& value)
{
    _output.emplace_back(pin, value);
}