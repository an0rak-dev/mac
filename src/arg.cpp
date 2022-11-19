#include "arg.hpp"

Arg::Arg(const char* name, bool optional) : name(name), optional(optional) {

}

Arg::~Arg() {

}

Arg* Arg::setDescription(const char* desc) {
    this->description = desc;
    return this;
}

bool Arg::isOptional() const {
    return this->optional;
}

const char* Arg::getName() const {
    return this->name;
}

const char* Arg::getDescription() const {
    return this->description;
}