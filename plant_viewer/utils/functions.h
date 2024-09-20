#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics/Color.hpp>
#include "raw_genom.h"

sf::Color change_color(const sf::Color& color, const sf::Color& delta) {
    sf::Color tmp{color};
    tmp.r += delta.r;
    tmp.g += delta.g;
    tmp.b += delta.b;
    tmp.a += delta.a;
    return tmp;
}

sf::Color make_sf_color(color color) {
    return sf::Color{color.r, color.g, color.b, color.a};
}

#endif //UTILS_H
