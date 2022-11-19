#include "standardparser.hpp"

#define OPTION_PREFIX '-'
#define EMPTY_VALUE ""

StandardParser::StandardParser(int argc, char** argv) {
    for (int i=1; i < argc; i++) {
        if (argv[i][0] == OPTION_PREFIX) {                     // It's an option (like '-h' or '--all')
            if (i+1 < argc && argv[i+1][0] != OPTION_PREFIX) { // The current option has a value (like '--size 10')
                this->elements.emplace(argv[i], argv[i+1]);
                i += 1;
            } else {                                           // It's a standalone option (like '--help')
                this->elements.emplace(argv[i], EMPTY_VALUE);
            }
        } else {                                               // It's a mandatory valye (like a filepath)
            this->elements.emplace(argv[i], EMPTY_VALUE);
        }
    }
}

StandardParser::~StandardParser() {

}