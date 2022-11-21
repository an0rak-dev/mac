#pragma once

#include <string>

/**
 Arg represents a single command line argument that should be pass during program invokation.
*/
class Arg {
    public:
        Arg(std::string name, bool optional=false);
        virtual ~Arg();
        /**
         Set the description of the argument if needed for a help command.
        */
        Arg* setDescription(std::string desc);

        /**
         Returns true if the argument is an option, false if it's a mandatory one.
        */
        bool isOptional() const;
        std::string getName() const;
        std::string getDescription() const;
        std::string getValue() const;
        void setValue(std::string val);

    private:
        std::string name;
        bool optional;
        std::string description;
        std::string value;
};