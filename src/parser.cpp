#include "parser.hpp"

Parser::Parser() = default;

Parser::~Parser() = default;

bool Parser::containsOption(std::string arg) {
    auto entry = this->options.find(arg);
    return entry != this->options.end();
}

std::string Parser::getOption(std::string arg) {
    return this->options.at(arg);
}

std::vector<std::string> Parser::getInputs() {
    return this->inputs;
}