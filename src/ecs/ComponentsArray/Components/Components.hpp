/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

/**
 * @brief Components of the ecs can add more if needed
 * 
 */

struct Clock {
    sf::Time time;
    sf::Clock clock;
    sf::Time _time;
    sf::Clock _clock;
    sf::Time __time;
    sf::Clock __clock;
};

struct Size {
    float width = 0.0f;
    float height = 0.0f;
};

struct Speed {
    float speed = 0.0f;
};

struct Position {
    float x = 0.0f;
    float y = 0.0f;
};

struct Sprite {
    sf::Sprite sprite;
};

struct HitBox {
    int width = 0;
    int height = 0;
};

struct Tag {
    std::string tag;
    std::string textureTag;
};

struct Text {
    sf::Text text;
    sf::Font font;
    std::string str;
};

struct Drawable {
    bool drawable = true;
};

#endif /* !COMPONENTS_HPP_ */
