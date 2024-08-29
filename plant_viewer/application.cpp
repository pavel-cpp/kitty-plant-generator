#include "application.h"
#include "thread"

application::application(const genom& gen)
    : drawer_ {gen, window_}
{
}

int application::exec() {
    window_.create(sf::VideoMode {800, 600}, "Viewer");
    std::thread event_loop {*this, application::event_loop};



    event_loop.join();
    return 0;
}

void application::event_loop() {
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            process_events(event);
        }
    }
}

void application::process_events(const sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window_.close();
    }
}
