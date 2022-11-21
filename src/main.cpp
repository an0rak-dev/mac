#include <iostream>

#include "arg.hpp"
#include "command.hpp"
#include "standardparser.hpp"

void run(Command& cmd);

int main(int argc, char** argv) {
    StandardParser parser(argc, argv);

    Arg filepathArg("filepath");

    Command macCmd("mac");
    macCmd.setHelp("Create a 3D mesh from the given source file.");
    macCmd.addArgument(filepathArg);
    macCmd.setAction(run);

    return macCmd.execute(parser);
}

void run(Command& cmd) {
    std::string filepath = cmd.getArgument("filepath").value();
    std::cout << "file is : " << filepath << std::endl;
}