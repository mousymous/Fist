#include "includes.hpp"
#ifndef WINDOWCLASS_HPP
#define WINDOWCLASS_HPP

// A Class related to window activity
class Window_class {
public:

    // Constructor that initialize both the window_attribute structure and the window variable
    Window_class() : 
        window_attribute(),
        window(sf::VideoMode(window_attribute.WINDOW_WIDTH, window_attribute.WINDOW_HEIGHT), window_attribute.WINDOW_TITLE)
    {
        logger::FILE_LOG_INTO -> info("Window: Initializing");      // Logs information 
    };

    // window loop events
    void window_initialize() {
        
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
            window.display();
        }
    }    

private:
    struct Window_attribute {
        const std::uint16_t WINDOW_WIDTH {900};
        const std::uint16_t WINDOW_HEIGHT {600};
        const std::string WINDOW_TITLE {"FIST"};
    }; 

    Window_attribute window_attribute;
    sf::RenderWindow window;

};

#endif // WINDOWCLASS_HPP