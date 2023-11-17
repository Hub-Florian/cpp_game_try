/*
** EPITECH PROJECT, 2023
** Hub_toulouse_citygame
** File description:
** main
*/

#include "Game.hpp"
#include "../graphic/Graphic.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

void Game::init_tiles(int i, int j)
{
    std::ifstream file("configFiles/tiles.json");

    if (!file.is_open())
        exit(84);
    nlohmann::json tilesJson;
    file >> tilesJson;
    file.close();

    auto entity = reg.spawn_entity();
    reg.add_component<Position>(entity, Position());
    reg.add_component<Size>(entity, Size());
    reg.add_component<Drawable>(entity, Drawable());
    reg.add_component<Sprite>(entity, Sprite());
    reg.add_component<Tag>(entity, Tag());
    reg.add_component<HitBox>(entity, HitBox());

    auto &sprite = reg.get_components<Sprite>();
    auto &position = reg.get_components<Position>();
    auto &size = reg.get_components<Size>();
    auto &tag = reg.get_components<Tag>();
    auto &hitbox = reg.get_components<HitBox>();

    tag[entity]->tag = tilesJson["tile"][0]["tag"];
    tag[entity]->textureTag = tilesJson["tile"][0]["textureTag"];
    rect[tag[entity]->tag] = {tilesJson["tile"][0]["left"], tilesJson["tile"][0]["top"], tilesJson["tile"][0]["width"], tilesJson["tile"][0]["height"]};
    hitbox[entity]->width = tilesJson["tile"][0]["hitboxWidth"];
    hitbox[entity]->height = tilesJson["tile"][0]["hitboxHeight"];
    size[entity]->width = tilesJson["tile"][0]["scale"];
    size[entity]->height = tilesJson["tile"][0]["scale"];
    hitbox[entity]->width *= size[entity]->width;
    hitbox[entity]->height *= size[entity]->height;
    position[entity]->x = i * hitbox[entity]->width;
    position[entity]->y = j * hitbox[entity]->height;
}

void Game::registerComponents()
{
    reg.register_component<Position>();
    reg.register_component<Size>();
    reg.register_component<Speed>();
    reg.register_component<Sprite>();
    reg.register_component<Tag>();
    reg.register_component<Text>();
    reg.register_component<Drawable>();
    reg.register_component<HitBox>();
    reg.register_component<Clock>();
}

void Game::run()
{
    registerComponents();
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            init_tiles(i, j);
    Graphic graphic(reg, scene, rect);
    graphic.gameLoop();
}
