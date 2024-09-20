#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "drawer.h"
#include "raw_genom.h"

class application {
public:
    application() = delete;
    explicit application(const raw_genom& gen);
    int exec();

private:
    sf::RenderWindow window_;
    drawer drawer_;

private:
    void event_loop();
    void process_events(const sf::Event& event);
};

#endif //APPLICATION_H
