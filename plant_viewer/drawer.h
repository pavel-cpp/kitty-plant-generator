#ifndef DRAWER_H
#define DRAWER_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "slices/animated_slice.h"

#include "raw_genom.h"
#include "tree_builder.h"

class drawer {
    public:
        drawer() = delete;

        drawer(const raw_genom& gen, sf::RenderWindow& window) :
            window_{window} {
            genom_ = make_drawable_genom_tree(gen, [](const raw_slice& raw) {
                return std::make_shared<animated_slice>(raw);
            });
            prev_gen_it_ = ++genom_.begin_breadth_first();
            cur_gen_it_ = ++genom_.begin_breadth_first();
        }

        void draw_next() {
            if (is_done()) {
                return;
            }
            if (cur_gen_it_ == ++genom_.begin_breadth_first()) {
                cur_gen_it_->get()->set_position(sf::Vector2f {500, 500});
            } else {
                auto point = prev_gen_it_->get()->get_done_position();
                cur_gen_it_->get()->set_position(point);
            }
            while (!cur_gen_it_->get()->is_done()) {
                window_.draw(*(cur_gen_it_->get()));
            }
            prev_gen_it_ = cur_gen_it_;
            ++cur_gen_it_;
        }

        [[nodiscard]] bool is_done() const {
            if (cur_gen_it_ == genom_.end_breadth_first()) {
                return true;
            }
            return false;
        }

    private:
        tree<std::shared_ptr<abstract_drawable_slice>> genom_;
        tree<std::shared_ptr<abstract_drawable_slice>>::breadth_first_iterator cur_gen_it_;
        tree<std::shared_ptr<abstract_drawable_slice>>::breadth_first_iterator prev_gen_it_;

        sf::RenderWindow& window_;
};

#endif //DRAWER_H
