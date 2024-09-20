#ifndef RAW_GENOM_H
#define RAW_GENOM_H

#include <cstdint>
#include <vector>

struct color {
    uint8_t r {};
    uint8_t g {};
    uint8_t b {};
    uint8_t a {};
};

struct raw_slice {
    int32_t radius_in {};
    int32_t radius_delta {};
    color color_in {};
    color color_delta {};
    uint16_t length {};
    int16_t angle {};
    int8_t child_angle_bias {};
    int8_t angle_delta {};
    uint8_t amount_of_children {};
    int8_t curvature {};
};

using raw_genom = std::vector<raw_slice>;

#endif //LAYER_CONTAIER_H
