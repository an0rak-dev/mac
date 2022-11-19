#include "parser.hpp"

Parser::Parser() = default;

Parser::~Parser() = default;

bool Parser::contains(const char* arg) {
    auto entry = this->elements.find(arg);
    return entry != this->elements.end();
}

std::string Parser::get(const char* arg) {
    return this->elements.at(arg);
}