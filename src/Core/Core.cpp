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
    setPendingInput(name, tristateValue);
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
    applyPendingInputs();
    for (auto &component : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.second.get());
        comp->simulate(_tick);
    }
    _tick++;
}

void nts::Core::process(const std::string input)
{
    try {
        if (input == "display")
            dump();
        else if (input == "simulate")
            simulate();
        else if (input.find('=') != std::string::npos)
            editValueViaInput(input);
        else if (input == "loop")
            loopEmulate();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::map<std::string, nts::Tristate> nts::Core::getInputs()
{
    std::map<std::string, Tristate> inputs;

    for (auto &[name, component] : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.get());
        if (comp->getType() == IComponent::INPUT)
            inputs[name] = comp->compute(1);
        if (comp->getType() == IComponent::CLOCK)
            inputs[name] = comp->compute(1);
    }
    return inputs;
}

std::map<std::string, nts::Tristate> nts::Core::getOutputs()
{
    std::map<std::string, Tristate> outputs;

    for (auto &[name, component] : _components) {
        AComponent *comp = dynamic_cast<AComponent *>(component.get());
        if (comp->getType() == IComponent::OUTPUT)
            outputs[name] = comp->compute(1);
    }
    return outputs;
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
    try {
        addLinks(parser);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    loop();
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
    std::cout << "tick: " << getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &p : getInputs()) {
        std::cout << "  " <<  p.first << ": " << valueToString(p.second) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &p : getOutputs()) {
        std::cout << "  " <<  p.first << ": " << valueToString(p.second)  << std::endl;
    }
}

std::size_t nts::Core::getTick() const
{
    return _tick;
}
