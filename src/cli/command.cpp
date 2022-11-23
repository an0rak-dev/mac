#include "cli/command.hpp"

#include <iostream>

Command::Command(std::string name) : name(name) {

}

Command::~Command() {

}

void Command::setHelp(std::string helpTxt) {
    this->helpText = helpTxt;
}

void Command::setAction(std::function<void(Command&)> func) {
    this->action = func;
}

void Command::addArgument(Arg &argument) {
    if (argument.isOptional()) {
        this->optionalArguments.push_back(argument);
    } else {
        this->mandatoryArguments.push_back(argument);
    }
}

std::optional<std::string> Command::getArgument(std::string argName) {
    for (auto arg = this->mandatoryArguments.begin(); arg != this->mandatoryArguments.end(); arg++) {
        if (argName == (*arg).getName()) {
            return std::optional((*arg).getValue());
        } 
    }
    for (auto arg = this->optionalArguments.begin(); arg != this->optionalArguments.end(); arg++) {
        if (argName == (*arg).getName()) {
            return std::optional((*arg).getValue());
        } 
    }
    return std::nullopt;
}

int Command::execute(Parser& parser) {
    try {
        this->fillArgs(parser);
        if (this->getArgument("--help")) {
            this->printHelp();
        } else {
            this->action(*this);
        }
    } catch(std::exception &e) {
        std::cerr << "Error : " << e.what() << std::endl << std::endl;
        this->printUsage();
        return 1;
    }
    return 0;
}

void Command::printUsage() {
    std::cout << "usage: " << this->name;
    if (!this->optionalArguments.empty()) {
        std::cout << " [options]";
    }
    for (int i=0; i < this->mandatoryArguments.size(); i++) {
        std::cout << " <" << this->mandatoryArguments[i].getName() << ">";
    }
    std::cout << std::endl;
    
    this->printHelp();
}

void Command::printHelp() {
    std::cout << this->helpText << std::endl << std::endl;
    std::cout << "Available options :" << std::endl;
    this->printSingleOption("help", "Print this help text");
    for (int i=0; i < this->optionalArguments.size(); i++) {
        Arg option = this->optionalArguments[i];
        this->printSingleOption(option.getName(), option.getDescription());
    }
}

void Command::printSingleOption(std::string optionName, std::string description) {
    std::cout << "  " 
            << "--" << optionName
            << " : "
            << description
            << std::endl;
}

void Command::fillArgs(Parser& parser) {
    std::vector<std::string> inputs = parser.getInputs();
    if (this->mandatoryArguments.size() != inputs.size()) {
        throw std::exception("Missing mandatory argument");
    }
    for (int i=0; i < this->mandatoryArguments.size(); i++) {
        this->mandatoryArguments.at(i).setValue(inputs.at(i));
    }
    for (auto arg = this->optionalArguments.begin(); arg != this->optionalArguments.end(); arg++) {
        if (parser.containsOption((*arg).getName())) {
            (*arg).setValue(parser.getOption((*arg).getName()));
        }
    }
}