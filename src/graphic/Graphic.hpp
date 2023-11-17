/*
** EPITECH PROJECT, 2023
** Hub_toulouse_citygame
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include "../game/Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <iostream>


class Graphic {
    public:
        Graphic(Registry &reg, Scene &scene, std::unordered_map<std::string, Rect> &rect);
        void gameLoop();
        ~Graphic() = default;
    protected:
    private:
        void init_window();
        void init_sprites();
        void set_textures();
        void draw_sprites();
    private:
        sf::RenderWindow window;
        Registry reg;
        std::unordered_map<std::string, Rect> rect;
        std::unordered_map<std::string, sf::Texture> textures;
        Scene scene;
};

#endif /* !GRAPHIC_HPP_ */
