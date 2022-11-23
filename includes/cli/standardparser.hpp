#pragma once

#include "parser.hpp"

/**
 * The implementation of the Parser class for the standard C/C++ main input.
*/
class StandardParser : public Parser {
    public:
        StandardParser(int argc, char** argv);
        virtual ~StandardParser();
};