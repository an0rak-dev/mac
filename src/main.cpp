#include <fstream>
#include <iostream>

#include "cli/arg.hpp"
#include "cli/command.hpp"
#include "cli/standardparser.hpp"

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
    std::ifstream inputStream(filepath);
    if (!inputStream.is_open()) {
        throw std::exception("Failed to open the wanted file");
    }
    std::string sourceContent = "";
    while (inputStream.good()) {
        std::string line = "";
        std::getline(inputStream, line);
        sourceContent = sourceContent.append(line).append("\n");
    }
    
    std::cout << "Content of the file is :" << std::endl << std::endl 
        << sourceContent
        << std::endl << std::endl;
}