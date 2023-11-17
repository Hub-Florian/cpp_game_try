/*
** EPITECH PROJECT, 2023
** Hub_toulouse_citygame
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../ecs/ComponentsArray/Systems/System.hpp"
#include "../ecs/Registry.hpp"

enum Scene {
    MENU,
    GAME,
    PAUSE,
    END
};

struct Rect {
    int left;
    int top;
    int width;
    int height;
};

class Game {
    public:
        Game() = default;
        ~Game() = default;
        void run();
    protected:
    private:
        Scene scene;
        System system;
        Registry reg;
        std::unordered_map<std::string, Rect> rect;
    private:
        void init_rect();
        void init_tiles(int i, int j);
        void registerComponents();
};

#endif /* !GAME_HPP_ */
