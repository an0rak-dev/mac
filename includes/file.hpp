#pragma once

#include <string>  

class File {
    public:
        File(std::string path);
        virtual ~File();
        bool exists();
        std::string read();

    private:
        std::string path;
};