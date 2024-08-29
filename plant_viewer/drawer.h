#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.hpp>

#include "genom.h"

class drawer_interpreter {
public:
    drawer_interpreter() = delete;
    drawer_interpreter(const genom& gen, sf::RenderWindow& window, sf::Vector2f point) : gen_ {gen}, gen_it {gen_.begin()}, window_ {window}, point_ {point} {}

    void draw_next();

    bool is_done() const;

private:
    genom gen_;
    genom::iterator gen_it;

    sf::RenderWindow& window_;
    sf::Vector2f point_;
};


#endif //DRAWER_H
