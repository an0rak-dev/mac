#pragma once

/**
 Arg represents a single command line argument that should be pass during program invokation.
*/
class Arg {
    public:
        Arg(const char* name, bool optional=false);
        virtual ~Arg();
        /**
         Set the description of the argument if needed for a help command.
        */
        Arg* setDescription(const char* desc);

        /**
         Returns true if the argument is an option, false if it's a mandatory one.
        */
        bool isOptional() const;
        const char* getName() const;
        const char* getDescription() const;

    private:
        const char* name;
        bool optional;
        const char* description;
};