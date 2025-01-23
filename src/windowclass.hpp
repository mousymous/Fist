#include "includes.hpp"
#ifndef WINDOWCLASS_HPP
#define WINDOWCLASS_HPP

// A Class related to window activity
class Window_Class {
public:

    // Constructor that initialize both the window_attribute structure and the window variable
    Window_Class() : 
        window_attribute(),
        window(sf::VideoMode(window_attribute.WINDOW_WIDTH, window_attribute.WINDOW_HEIGHT), window_attribute.WINDOW_TITLE)
    {
        logger::FILE_LOG_INTO -> info("Window: Initializing");      // Logs information 
    };

    // window loop events
    void window_initialize(Background_Class &background_class) {
        
        window.setFramerateLimit(60);
        sf::Event events;
        // Checks if window initialazation has been failed then exits the program
    
        if (window.isOpen() == false) {
            logger::FILE_LOG_INTO -> error("Window: Initialization Failed");
            exit(EXIT_FAILURE);
        }
        // Checks if the Close button has been press to exit
        while(window.isOpen()) {
            while(window.pollEvent(events)) {
                if(events.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Render Display Here
            window.clear();
            window.draw(background_class.background_sprite);
            window.display();
        }
    }

    const sf::Vector2u get_window_size() {
        return window.getSize();
    }

private:
    struct Window_Attribute {
        constexpr static std::uint16_t WINDOW_WIDTH {900};
        constexpr static std::uint16_t WINDOW_HEIGHT {600};
        std::string WINDOW_TITLE {"FIST"};
    }; 

    Window_Attribute window_attribute;
    sf::RenderWindow window;

};

#endif // WINDOWCLASS_HPP