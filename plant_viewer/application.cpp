#include "application.h"
#include <thread>

application::application(const raw_genom& gen)
    : drawer_ {gen, window_}
{
}

int application::exec() {
    using namespace std::chrono_literals;

    window_.create(sf::VideoMode {800, 600}, "Viewer");
    // std::thread event_loop {&application::event_loop, this};
    window_.clear();
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            process_events(event);
        }
        if (!drawer_.is_done()) {
            drawer_.draw_next();
            window_.display();
            std::this_thread::sleep_for(100ms);
        }
    }

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
