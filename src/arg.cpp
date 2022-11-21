#include "arg.hpp"

Arg::Arg(std::string name, bool optional) : name(name), optional(optional) {

}

Arg::~Arg() {

}

Arg* Arg::setDescription(std::string desc) {
    this->description = desc;
    return this;
}

bool Arg::isOptional() const {
    return this->optional;
}

std::string Arg::getName() const {
    return this->name;
}

std::string Arg::getDescription() const {
    return this->description;
}

std::string Arg::getValue() const {
    return this->value;
}

void Arg::setValue(std::string val) {
    this->value = val;
}