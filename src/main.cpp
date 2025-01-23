#include "includes.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {

    logger::FILE_LOG_INTO -> info("Main Function Initialized");

    Window_class window_class;
    window_class.window_initialize();
    return EXIT_SUCCESS;
}