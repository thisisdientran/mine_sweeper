#ifndef WINDOW_CONSTANT_H
#define WINDOW_CONSTANT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "../spriteSheetCutter/SpriteSheetCutter.h"

// screen resolution
const int SCREEN_X = 960;
const int SCREEN_Y = 720;
const int GRID_X = 5;
const int GRID_Y = 5;
const int MINE_P = 20;
const int CELL_SIZE = (int)(std::min(SCREEN_X/GRID_X,SCREEN_Y/GRID_Y));

int map[GRID_Y][GRID_X];
int map_view[GRID_Y][GRID_X];

//Init window
sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y),
                                                    "MINE SWEEPER",sf::Style::Close);

//Load file
sf::Texture texture;
sf::Font font;

void initFont();
void initTextures();

void initFont() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error: Could not load font 'arial.ttf'." << std::endl;
        exit(1);
    }
}

void initTextures() {
    if(!texture.loadFromFile("minesweep_cut.png")) exit(1);
}

#endif