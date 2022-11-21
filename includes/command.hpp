#pragma once

#include <functional> 
#include <optional>
#include <string>
#include <vector>
#include "arg.hpp"
#include "parser.hpp"

/**
 Command represent a command line action to invoke.
*/
class Command {
    public:
        Command(std::string name);
        virtual ~Command();

        /**
         * Set the help text of the command to be displayed if it's invoked with '--help'.
        */
        void setHelp(std::string helpTxt);

        /**
         * Set the behaviour of the command.
        */
        void setAction(std::function<void(Command&)> func);

        /**
         * Add a possible argument that the command may accept.
        */
        void addArgument(Arg &argument);

        /**
         * Return the value of the argument with the given name if it's set.
        */
        std::optional<std::string> getArgument(std::string argName);
        
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
        void printSingleOption(std::string optionName, std::string description);
        void fillArgs(Parser& parser);
        std::string name;
        std::string helpText;
        std::vector<Arg> mandatoryArguments;
        std::vector<Arg> optionalArguments;
        std::function<void(Command&)> action;
};