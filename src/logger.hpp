#include "includes.hpp"
#ifndef LOGGER_HPP
#define LOGGER_HPP

/*
    Function to Initialize Logger
    If it returns a value the logger has been successfully initialized, else then it failed
*/

std::shared_ptr<spdlog::logger> initialize_logger(){
    try {
        auto file_log = spdlog::basic_logger_mt("log-file", "../../logs/logs.txt");
        file_log -> info("Logger: Initialized Success");
        return file_log;
    } catch (spdlog::spdlog_ex &error) {
        std::cerr << "Error: " << error.what()  << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Global Variable of the logger variable in a namespace
namespace logger {
    std::shared_ptr<spdlog::logger> FILE_LOG_INTO = initialize_logger();
}

#endif