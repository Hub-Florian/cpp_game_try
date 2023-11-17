/*
** EPITECH PROJECT, 2023
** Hub_toulouse_citygame
** File description:
** graphic
*/

#include "Graphic.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

Graphic::Graphic(Registry &reg, Scene &scene, std::unordered_map<std::string, Rect> &rect)
{
    this->reg = reg;
    this->scene = scene;
    this->rect = rect;
}

void Graphic::set_textures()
{
    sf::Texture textureTiles;
    textureTiles.loadFromFile("assets/tiles_set_1.png");
    textures["tile"] = textureTiles;
    
}

void Graphic::init_sprites()
{
    auto &sprite = reg.get_components<Sprite>();
    auto &tag = reg.get_components<Tag>();
    auto &size = reg.get_components<Size>();
    auto &position = reg.get_components<Position>();

    for (size_t i = 0; sprite.size() > i; i++) {
        sprite[i]->sprite.setTexture(textures[tag[i]->textureTag]);
        sprite[i]->sprite.setTextureRect(sf::IntRect(rect[tag[i]->tag].left, rect[tag[i]->tag].top, rect[tag[i]->tag].width, rect[tag[i]->tag].height));
        sprite[i]->sprite.setScale(size[i]->width, size[i]->height);
        sprite[i]->sprite.setPosition(position[i]->x, position[i]->y);
        window.draw(sprite[i]->sprite);
    }
}

void Graphic::init_window()
{
    std::ifstream file("configFiles/window.json");

    if (!file.is_open())
        exit(84);
    nlohmann::json windowJson;
    file >> windowJson;
    file.close();

    int width = windowJson["window"]["width"];
    int height = windowJson["window"]["height"];
    int frame = 0;
    std::string title = windowJson["window"]["title"];

    window.create(sf::VideoMode(width, height), title);

}

void Graphic::gameLoop()
{
    init_window();
    set_textures();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        init_sprites();
        window.display();
    }
}
