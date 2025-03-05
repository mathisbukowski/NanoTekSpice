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
            return 84;
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
        this->simulate();
        this->dump();
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
    Tristate tristateValue;

    if (pos == std::string::npos)
        throw CoreError("Error: invalid input");
    name = input.substr(0, pos);
    value = input.substr(pos + 1);
    if (value != "0" && value != "1" && value != "U")
        throw CoreError("Error: invalid value");
    if (_components.find(name) == _components.end())
        throw CoreError("Error: invalid input");
    tristateValue = value == "U" ? UNDEFINED : value == "1" ? TRUE : FALSE;
    this->setPendingInput(name, tristateValue);
}

void nts::Core::setPendingInput(const std::string& name, Tristate value)
{
    _pendingInputs[name] = value;
}

void nts::Core::applyPendingInputs()
{
    for (const auto& [name, value] : _pendingInputs) {
        AComponent *comp = dynamic_cast<AComponent *>(_components[name].get());
        comp->setPinValue(1, value);
    }
    _pendingInputs.clear();
}

void nts::Core::simulate()
{
    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        comp->simulate(_tick);
    }
    this->applyPendingInputs();
    _tick++;
}

std::map<std::string, nts::Tristate> nts::Core::getOutputs()
{
    std::map<std::string, Tristate> outputs;

    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        if (comp->getType() == IComponent::OUTPUT)
            outputs[comp->getName()] = comp->computeInput(1);
    }
    return outputs;
}

std::map<std::string, nts::Tristate> nts::Core::getInputs()
{
    std::map<std::string, Tristate> inputs;

    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        if (comp->getType() == IComponent::INPUT || comp->getType() == IComponent::CLOCK)
            inputs[comp->getName()] = comp->getPinValue(1);
    }
    return inputs;
}

void nts::Core::process(const std::string input)
{
    try {
        if (input == "display")
            this->dump();
        else if (input == "simulate")
            this->simulate();
        else if (input.find('=') != std::string::npos)
            this->editValueViaInput(input);
        else if (input == "loop")
            this->loopEmulate();
        else
            std::cout << "Unknown command" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
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
}

void nts::Core::addLinks(Parser *parser)
{
    for (auto &link : parser->_links) {
        const auto &[name1, pin1] = link.first;
        const auto &[name2, pin2] = link.second;

        if (_components.find(name1) == _components.end() || _components.find(name2) == _components.end())
            throw CoreError("Error: invalid link");
        AComponent *comp1 = dynamic_cast<AComponent *>(_components[name1].get());
        AComponent *comp2 = dynamic_cast<AComponent *>(_components[name2].get());
        comp1->setLink(pin1, *comp2, pin2);
        comp2->setLink(pin2, *comp1, pin1);
    }
}


int nts::Core::loop()
{
    std::string input;

    signal(SIGINT, [](int) { this->exit(); });
    while (true) {
        std::cout << "> ";
        if (std::getline(std::cin, input).eof())
            std::exit(0);
        if (input == "exit")
            this->exit();
        this->process(input);
    }
}


int nts::Core::run(const char *file)
{
    Parser *parser = new Parser();

    if (!file) {
        std::cerr << "Usage: ./nanotekspice [file]" << std::endl;
        return 84;
    }
    if (this->getAllArgs(parser, file) == 84)
        return 84;
    this->addComponents(parser);
    try {
        this->addLinks(parser);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    this->loop();
    return 0;
}

std::string nts::Core::valueToString(Tristate &value)
{
    if (value == TRUE)
        return "1";
    if (value == FALSE)
        return "0";
    return "U";
}

void nts::Core::dump()
{
    std::cout << "tick: " << this->getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &p : this->getInputs()) {
        std::cout << "  " <<  p.first << ": " << this->valueToString(p.second) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &p : this->getOutputs()) {
        std::cout << "  " <<  p.first << ": " << this->valueToString(p.second)  << std::endl;
    }
}

std::size_t nts::Core::getTick() const
{
    return _tick;
}
