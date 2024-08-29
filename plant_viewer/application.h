#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "drawer.h"
#include "genom.h"

class application {
public:
    application() = delete;
    explicit application(const genom& gen);
    int exec();

private:
    sf::RenderWindow window_;
    drawer_interpreter drawer_;

private:
    void event_loop();
    void process_events(const sf::Event& event);
};

#endif //APPLICATION_H
