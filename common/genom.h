#ifndef GENOM_H
#define GENOM_H

#include <array>
#include <cstdint>
#include <vector>

struct color {
    uint8_t r {};
    uint8_t g {};
    uint8_t b {};
    uint8_t a {};
};

struct slice {
    int radius_in {};
    int radius_delta {};
    color color_in {};
    color color_delta {};
    int length {};
    int angle {};
    uint8_t amount_of_children {};
    char curvature {};
};

using genom = std::pmr::vector<slice>;

#endif //LAYER_CONTAIER_H
