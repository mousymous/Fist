#include "includes.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background_Class {
public:

    Background_Class(const sf::Vector2u &window_size) {
        logger::FILE_LOG_INTO -> info("Background: Initilizing");
        setup_background(window_size);
    };

    sf::Sprite background_sprite;
    sf::Texture background_texture;

    void setup_background(const sf::Vector2u &window_size) {
        const std::string background_path {"../../resources/background/background-placeholder.jpeg"};
        if (!background_texture.loadFromFile(background_path)) {
            logger::FILE_LOG_INTO -> error("Background: can't locate file" < background_path);
            exit(EXIT_FAILURE);
        } 

        background_sprite.setTexture(background_texture);
        background_sprite.setScale(
            static_cast<float>(window_size.x) / background_texture.getSize().x,
            static_cast<float>(window_size.x) / background_texture.getSize().x
        );
        logger::FILE_LOG_INTO -> info("Background: initialize success");
    }
};

#endif