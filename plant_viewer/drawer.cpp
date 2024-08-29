#include "drawer.h"

void drawer_interpreter::draw_next() {
    if (gen_it->length == 0) {
        return;
    }
    sf::CircleShape circle;
    auto& slice {*gen_it};
    circle.setRadius(slice.radius_in);
    circle.setPosition(point_);
    circle.setFillColor(sf::Color {slice.color_in.r, slice.color_in.g, slice.color_in.b, slice.color_in.a});

    slice.length -= 1;
    // TODO: angle
}

bool drawer_interpreter::is_done() const {

}

