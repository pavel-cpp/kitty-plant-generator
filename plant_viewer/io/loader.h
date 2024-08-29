#ifndef LOADER_H
#define LOADER_H

#include <filesystem>
#include <fstream>

#include "genom.h"

genom load(std::filesystem::path path) {
    std::ifstream file {path, std::ios::binary | std::ios::in};
    genom gen;
    size_t size;
    file.read(reinterpret_cast<char *>(&size), sizeof(size_t));
    gen.resize(size);
    file.read(reinterpret_cast<char *>(gen.data()), size * sizeof(slice));
    return gen;
}

#endif //LOADER_H
