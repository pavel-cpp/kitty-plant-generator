#ifndef LOADER_H
#define LOADER_H

#include <filesystem>
#include <fstream>

#include "raw_genom.h"

inline raw_genom load(std::filesystem::path path) {
    std::ifstream file {path, std::ios::binary | std::ios::in};
    if (!file) {
        throw std::runtime_error("Cannot open file");
    }
    raw_genom gen;
    size_t size;
    file.read(reinterpret_cast<char *>(&size), sizeof(size_t));
    gen.resize(size);
    file.read(reinterpret_cast<char *>(gen.data()), size * sizeof(raw_slice));
    return gen;
}

#endif //LOADER_H
