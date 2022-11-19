#pragma once

#include <functional> 
#include <vector>
#include "arg.hpp"
#include "parser.hpp"

/**
 Command represent a command line action to invoke.
*/
class Command {
    public:
        Command(const char* name);
        virtual ~Command();

        /**
         * Set the help text of the command to be displayed if it's invoked with '--help'.
        */
        void setHelp(const char* helpTxt);

        /**
         * Set the behaviour of the command.
        */
        void setAction(std::function<void(Parser&)> func);

        /**
         * Add a possible argument that the command may accept.
        */
        void addArgument(Arg &argument);
        
        /**
         * Run the action linked to the calling command.
         * 
         * If the command was invoked with '--help', then print the help sentence
         * and return 0.
         * If the action throws an error, print the usage sentence (invokation syntax
         * + help text) and return 1.
         * Otherwise, run the action and return 0.
        */
        int execute(Parser& parser);

    private:
        void printUsage();
        void printHelp();
        void printSingleOption(const char* optionName, const char* description);
        const char* name;
        const char* helpText;
        std::vector<Arg> mandatoryArguments;
        std::vector<Arg> optionalArguments;
        std::function<void(Parser&)> action;
};