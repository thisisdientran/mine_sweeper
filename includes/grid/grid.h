#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <vector>
#include "../Constant/window-constant.h"
#include "../helper/helper.h"

class Grid{
    private:
        std::vector<sf::RectangleShape> rects;
        int num_boxes_in_width = SCREEN_X/20;
        int num_boxes_in_height = SCREEN_Y/20;        
    public:
        Grid();

        void create_grid();
        void display_grid();

        sf::RectangleShape get_rectangle(int posX, int posY);
        void onclick_rectangle(int posX, int posY);
        const sf::Vector2<int> get_box_position() const;
};

Grid::Grid(){
    create_grid();
}

void Grid::create_grid(){
    for(size_t i = 0; i <num_boxes_in_height;i++){
        for(size_t j = 0; j <num_boxes_in_height;j++){
            sf::RectangleShape rectangle(sf::Vector2f(20,20));
            rectangle.setFillColor(sf::Color(220, 220, 220));
            rectangle.setOutlineThickness(2);
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.move(sf::Vector2f(j*20,i*20));
            rects.push_back(rectangle);
        }
    }
}

const sf::Vector2<int> Grid::get_box_position() const{
    for(size_t i = 0; i <rects.size();i++){
        rects[i].getPosition();
    }
}

void Grid::display_grid(){
    for(size_t i = 0; i<rects.size(); i++){
        window.draw(rects[i]);
    }
}

sf::RectangleShape Grid::get_rectangle(int posX, int posY){
    // get range
    int min_range_x = posX - 20 - 1;
    int min_range_y = posY - 20 - 1;
    std::cout << min_range_x << " " << min_range_y << std::endl;
    
    // see if match any box
    for(size_t i = 0; i <rects.size();i++){
        if(rects[i].getPosition().x <= posX && rects[i].getPosition().x >= min_range_x)
            if(rects[i].getPosition().y <= posY && rects[i].getPosition().y >= min_range_y){
                std::cout << "returning rect: " << i<< ", with address: "<<&rects[i]<<std::endl;;
                return rects[i];
            }
                
    }
}


void Grid::onclick_rectangle(int posX, int posY){
    // get range
    int min_range_x = posX - 20 - 1;
    int min_range_y = posY - 20 - 1;
    std::cout << min_range_x << " " << min_range_y << std::endl;
    
    // see if match any box
    for(size_t i = 0; i <rects.size();i++){
        if(rects[i].getPosition().x <= posX && rects[i].getPosition().x >= min_range_x)
            if(rects[i].getPosition().y <= posY && rects[i].getPosition().y >= min_range_y){
                std::cout << "returning rect: " << i<< ", with address: "<<&rects[i]<<std::endl;;
                rects[i].setFillColor(sf::Color(0, 0, 0));
                break;
            }
                
    }
}


#endif