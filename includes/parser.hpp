#pragma once

#include <map>
#include <string>
#include <vector>

/**
 * Parser is the base class of the command line parsers.
 *
 * By itself, if you instanciate this class, it will parse
 * nothing, since it don't have any input.
 * You should extend this class and make your constructor 
 * match the kind of input you want to parse.
*/
class Parser {
    public:
        /**
         * Creates a new instance of Parser which does nothing.
        */
        Parser();
        virtual ~Parser();

        /**
         * Returns true if the given argument (a mandatory or an optional one)
         * was passed during the invokation.
        */
        bool containsOption(std::string argValue);

        /**
         * Returns the value of the given argument if it was passed during the 
         * invokation.
         * 
         * If the argument has no value (like '--all' or '--help'), then returns
         * an empty string.
         * If the argument was not present, then throws an exception.
        */
        std::string getOption(std::string arg);

        std::vector<std::string> getInputs();

    protected:
        /**
         * The command line elements parsed as '{argument, value}'. 
         * 
         * For example --help, should be parsed as '{"--help", ""}', and 
         * "--size 10", should be parsed as '{"--size", "10"}'.
        */
        std::map<std::string, std::string> options;

        std::vector<std::string> inputs;
};