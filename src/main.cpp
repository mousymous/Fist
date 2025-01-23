#include "includes.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {

    logger::FILE_LOG_INTO -> info("Main Function Initialized");

    Window_Class window_class;
    Background_Class background_class(window_class.get_window_size());
    window_class.window_initialize(background_class);
    return EXIT_SUCCESS;
}