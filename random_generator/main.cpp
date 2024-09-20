#include <iostream>
#include <fstream>

#include "raw_genom.h"

int main() {
    raw_slice slice {
        .radius_in {5},
        .radius_delta {},
        .color_in {
            .r {255},
            .g {255},
            .b {255},
            .a {255}
        },
        .color_delta {},
        .amount_of_children {2},
        .angle {0},
        .angle_delta {45},
        .child_angle_bias {-45},
        .length {20},
        .curvature {0}
    };
    // int seed;
    // size_t size;
    // std::cout << "Input seed: ";
    // std::cin >> seed;
    // std::cout << "Input size: ";
    // std::cin >> size;
    //
    // srand(seed);
    // raw_genom gen(size);
    // char *raw_gen_table {reinterpret_cast<char *>(gen.data())};
    // size_t gen_byte_size {gen.size() * sizeof(raw_slice)};
    // for (size_t i {}; i < gen_byte_size; ++i) {
    //     raw_gen_table[i] = rand() % 255;
    // }
    //
    // std::cout << "Generation done!" << std::endl
    //         << "Input path to save file" << std:: endl;
    // std:: cout << "Path: ";
    // std::string path;
    // std::cin >> path;
    //
    size_t size {5};
    {
        std::ofstream file("../flower.gen", std::ios::binary | std::ios::out);
        file.write(reinterpret_cast<char *>(&size), sizeof(size_t));
        file.write(reinterpret_cast<char *>(&slice), sizeof(raw_slice));
        slice.color_delta = color {0, 10, 10, 0};
        file.write(reinterpret_cast<char *>(&slice), sizeof(raw_slice));
        slice.color_delta = color {10, 10, 0, 0};
        file.write(reinterpret_cast<char *>(&slice), sizeof(raw_slice));
        slice.color_delta = color {10, 0, 10, 0};
        file.write(reinterpret_cast<char *>(&slice), sizeof(raw_slice));
    }
    std::cout << "Image saved!" << std::endl;
}