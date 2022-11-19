#include <iostream>

#include "arg.hpp"
#include "command.hpp"
#include "standardparser.hpp"

void run();

int main(int argc, char** argv) {
    StandardParser parser(argc, argv);

    Command macCmd("mac");
    macCmd.setHelp("Create a 3D mesh from the given source file.");
    macCmd.addArgument(Arg("filepath"));
    macCmd.setAction(run);

    return macCmd.execute(parser);
}

void run() {
    // TODO
}