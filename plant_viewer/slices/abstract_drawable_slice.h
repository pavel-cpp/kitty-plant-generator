#ifndef DRAWABLE_SLICE_H
#define DRAWABLE_SLICE_H

#include "abstract_slice.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class abstract_drawable_slice : public abstract_slice, public sf::Drawable {
    public:
        abstract_drawable_slice() = delete;
        explicit abstract_drawable_slice(raw_slice raw) : abstract_slice {raw} {}
        abstract_drawable_slice(raw_slice raw, sf::Vector2f pos) : abstract_slice {raw}, position_ {pos} {}
        [[nodiscard]] virtual bool is_done() const = 0;
        virtual void set_position(sf::Vector2f pos) {
            position_ = pos;
        }
        [[nodiscard]] sf::Vector2f get_position() const {
            return position_;
        }
        [[nodiscard]] sf::Vector2f get_done_position() const {
            sf::CircleShape sh;
            sh.setRotation(get_raw().angle);
            sh.move(0, get_raw().length);
            return sh.getPosition();
        }
    protected:
        sf::Vector2f position_ {};
};

#endif // DRAWABLE_SLICE_H
