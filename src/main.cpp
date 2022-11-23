#include <fstream>
#include <iostream>

#include "cli/arg.hpp"
#include "cli/command.hpp"
#include "cli/standardparser.hpp"
#include "file.hpp"

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
    File sourceFile(filepath);
    if (!sourceFile.exists()) {
        throw std::exception("Wanted file not found.");
    }
    std::string sourceContent = sourceFile.read();
    
    std::cout << "Content of the file is :" << std::endl << std::endl 
        << sourceContent
        << std::endl << std::endl;
}