#include <iostream>

#include "command.hpp"

Command::Command(const char* name) : name(name) {

}

Command::~Command() {

}

void Command::setHelp(const char* helpTxt) {
    this->helpText = helpTxt;
}

void Command::setAction(std::function<void(Parser&)> func) {
    this->action = func;
}

void Command::addArgument(Arg &argument) {
    if (argument.isOptional()) {
        this->optionalArguments.push_back(argument);
    } else {
        this->mandatoryArguments.push_back(argument);
    }
}

int Command::execute(Parser& parser) {
    if (parser.contains("--help")) {
        this->printHelp();
        return 0;
    }
    try {
        this->action(parser);
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

void Command::printSingleOption(const char* optionName, const char* description) {
    std::cout << "  " 
            << "--" << optionName
            << " : "
            << description
            << std::endl;
}