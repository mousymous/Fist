#include <SFML/Graphics.hpp>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

std::shared_ptr<spdlog::logger> initialize_logger(){
    try {
        auto file_log = spdlog::basic_logger_mt("log-file", "../logs/logs.txt");
        file_log -> info("Logger: Initialized Success");
        return file_log;
    } catch (spdlog::spdlog_ex &error) {
        std::cerr << "Error: " << error.what()  << std::endl;
        exit(-1);
    }
}

namespace logger {
    auto FILE_LOG_INTO = initialize_logger();
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {

    logger::FILE_LOG_INTO -> info("Main Function Initialized");
    return 0;
}