#include "file.hpp"

#include <fstream>
#include <filesystem>

File::File(std::string path) : path(path) {

}

File::~File() {

}

bool File::exists() {
    std::filesystem::path p(this->path);
    return std::filesystem::exists(p);
}

std::string File::read() {
    std::ifstream inputStream(this->path);
    if (!inputStream.is_open()) {
        throw std::exception("Failed to open the wanted file");
    }
    std::string content = "";
    while (inputStream.good()) {
        std::string line = "";
        std::getline(inputStream, line);
        content = content.append(line).append("\n");
    }
    return content;
}