//
// Created by Dave R. Smith on 10/14/24.
//

#ifndef SPRITE_SHEET_CUTTER_H
#define SPRITE_SHEET_CUTTER_H

#include <SFML/Graphics.hpp>
#include <cmath>

class SpriteSheetCutter  : public sf::Sprite
{
private:
    sf::Texture &_texture;
    int _rows, _cols;
    sf::IntRect _int_rect;
    void init();
    void setIntRectSize();
    void setupSprite();
public:
    SpriteSheetCutter(sf::Texture &texture, int rows, int col);

    void set(int row, int col);
    const float get1W() const;
    const float get1H() const;
};

#endif //SPRITESHEETCUTTER_H
