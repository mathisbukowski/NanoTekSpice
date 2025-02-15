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
#include "Components/ClockComponent.hpp"
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

volatile std::sig_atomic_t stopLoop = 0;

void signalHandler(int)
{
    stopLoop = 1;
}

void nts::Core::loopEmulate()
{
    std::signal(SIGINT, signalHandler);

    while (!stopLoop) {
        simulate();
        dump();
    }
}


void nts::Core::exit()
{
    std::cout << "exit" << std::endl;
    std::exit(0);
}

void nts::Core::editValueViaInput(const std::string& input)
{
    std::string name;
    std::string value;
    std::size_t pos = input.find('=');

    if (pos == std::string::npos)
        throw Core::CoreError("Error: invalid input");
    name = input.substr(0, pos);
    value = input.substr(pos + 1);
    if (value != "0" && value != "1" && value != "U")
        throw CoreError("Error: invalid value");
    if (_components.find(name) == _components.end())
        throw CoreError("Error: invalid input");
    AComponent *comp = dynamic_cast<AComponent *>(_components[name].get());
    comp->setPinValue(1, value == "U" ? UNDEFINED : value == "1" ? TRUE : FALSE);
}


void nts::Core::simulate()
{
    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        comp->simulate(_tick);
    }
    _tick++;
    getInputAndOutputToDisplay();
}

void nts::Core::process(const std::string input)
{
    if (input == "display")
        dump();
    else if (input == "simulate")
        simulate();
    else if (input.find('=') != std::string::npos)
        editValueViaInput(input);
    else if (input == "loop")
        loopEmulate();
    else
        std::cerr << "Error: invalid command" << std::endl;
}

void nts::Core::getInputAndOutputToDisplay()
{
    _output.clear();
    _input.clear();
    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        if (comp->getType() == IComponent::INPUT)
            _input.emplace_back(comp->getName(), comp->getPinValue(1) == TRUE ? "1" : comp->getPinValue(1) == FALSE ? "0" : "U");
        if (comp->getType() == IComponent::OUTPUT)
            _output.emplace_back(comp->getName(), comp->getPinValue(1) == TRUE ? "1" : comp->getPinValue(1) == FALSE ? "0" : "U");
        if (comp->getType() == IComponent::CLOCK)
            _input.emplace_back(comp->getName(), comp->getPinValue(1) == TRUE ? "1" : comp->getPinValue(1) == FALSE ? "0" : "U");
    }
}

void nts::Core::addComponents(Parser *parser)
{
    Factory factory;
    for (auto &chipset : parser->_chipsets) {
        std::unique_ptr<nts::IComponent> component = factory.createComponent(chipset.first);
        if (component) {
            AComponent *comp = dynamic_cast<AComponent *>(component.get());
            comp->setName(chipset.second);
            _components.insert(std::make_pair(chipset.second, std::move(component)));
        }
    }
    getInputAndOutputToDisplay();
}

void nts::Core::addLinks(Parser *parser)
{
    for (auto &link : parser->_links) {
        const auto &[name1, pin1] = link.first;
        const auto &[name2, pin2] = link.second;

        if (_components.find(name1) == _components.end() || _components.find(name2) == _components.end())
            throw Core::CoreError("Error: invalid link");
        _components[name1]->setLink(pin1, *_components[name2], pin2);
        _components[name2]->setLink(pin2, *_components[name1], pin1);
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
    addComponents(parser);
    addLinks(parser);
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