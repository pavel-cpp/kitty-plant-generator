#include "animated_slice.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

#include "utils/functions.h"

animated_slice::animated_slice(raw_slice raw)
    : abstract_drawable_slice{raw},
      cur_frame_{},
      last_frame_{get_raw().length}
{}

animated_slice::animated_slice(raw_slice raw, sf::Vector2f pos)
    : abstract_drawable_slice{raw, pos},
      cur_frame_{},
      last_frame_{get_raw().length}
{}

bool animated_slice::is_done() const {
    return cur_frame_ == last_frame_;
}

void animated_slice::renew() {
    cur_frame_ = 0;
}

void animated_slice::set_position(sf::Vector2f pos) {
    if (cur_frame_ != 0) {
        throw std::runtime_error {"Cannot set position because animation is started"};
    }
    abstract_drawable_slice::set_position(pos);
}

void animated_slice::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::CircleShape sh;
    sf::CircleShape circle;
    auto raw {get_raw()};
    circle.setRadius(raw.radius_in);
    circle.setPosition(get_position());
    circle.setFillColor(make_sf_color(raw.color_in));
    circle.setRotation(raw.angle);
    circle.setRadius(circle.getRadius() + raw.radius_delta * cur_frame_);
    circle.move(0, 1 * cur_frame_);
    for (size_t i{}; i < cur_frame_; ++i) {
        circle.setFillColor(
            change_color(
                circle.getFillColor(),
                make_sf_color(raw.color_delta)
            )
        );
    }
    target.draw(circle);
    ++cur_frame_;
}
