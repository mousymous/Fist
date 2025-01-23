#include <SFML/Graphics.hpp>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>
#include <cstdint>

/*
    Function to Initialize Logger
    If it returns a value the logger has been successfully initialized, else then it failed
*/

std::shared_ptr<spdlog::logger> initialize_logger(){
    try {
        auto file_log = spdlog::basic_logger_mt("log-file", "../logs/logs.txt");
        file_log -> info("Logger: Initialized Success");
        return file_log;
    } catch (spdlog::spdlog_ex &error) {
        std::cerr << "Error: " << error.what()  << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Global Variable of the logger variable in a namespace
namespace logger {
    auto FILE_LOG_INTO = initialize_logger();
}

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

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {

    logger::FILE_LOG_INTO -> info("Main Function Initialized");

    Window_class window_class;
    window_class.window_initialize();
    return EXIT_SUCCESS;
}