#ifndef ANIMATED_SLICE_H
#define ANIMATED_SLICE_H

#include "abstract_drawable_slice.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class animated_slice : public abstract_drawable_slice {
    public:
        animated_slice(raw_slice raw);
        animated_slice(raw_slice raw, sf::Vector2f pos);
        bool is_done() const override;
        void renew();
        void set_position(sf::Vector2f pos) override;
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    private:
        mutable size_t cur_frame_ {};
        size_t last_frame_ {};
};

#endif //ANIMATED_SLICE_H
