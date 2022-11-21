#include "standardparser.hpp"

#define OPTION_PREFIX '-'
#define EMPTY_VALUE ""

StandardParser::StandardParser(int argc, char** argv) {
    for (int i=1; i < argc; i++) {
        if (argv[i][0] == OPTION_PREFIX) {                     // It's an option (like '-h' or '--all')
            if (i+1 < argc && argv[i+1][0] != OPTION_PREFIX) { // The current option has a value (like '--size 10')
                this->options.emplace(argv[i], argv[i+1]);
                i += 1;
            } else {                                           // It's a standalone option (like '--help')
                this->options.emplace(argv[i], EMPTY_VALUE);
            }
        } else {                                               // It's a mandatory value (like a filepath)
            this->inputs.push_back(argv[i]);
        }
    }
}

StandardParser::~StandardParser() {

}