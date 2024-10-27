//
// Created by Dave R. Smith on 10/14/24.
//

#include "SpriteSheetCutter.h"

SpriteSheetCutter::SpriteSheetCutter(sf::Texture &texture, int rows, int cols)
    : _texture(texture), _rows(rows), _cols(cols)
{
    init();
}


void SpriteSheetCutter::init()
{
    setIntRectSize();
    setupSprite();
}

void SpriteSheetCutter::set(int row, int col)
{
    ///// make sure the row and col are valid
    _int_rect.top = _int_rect.height * row; // go y pos in nth row
    _int_rect.left = _int_rect.width * col; // go x pos in nth col
    sf::Sprite::setTextureRect(_int_rect);
}

void SpriteSheetCutter::setIntRectSize()
{ 
    _int_rect.width = std::round(_texture.getSize().x / _cols); // e.g: 600 / 12 = 50
    _int_rect.height = std::round(_texture.getSize().y / _rows); // 600 / 12 = 50 => wxd = 50x50 
}

void SpriteSheetCutter::setupSprite()
{
    sf::Sprite::setTexture(_texture); // set texture
    sf::Sprite::setTextureRect(_int_rect); // set the wxd 
}

const float SpriteSheetCutter::get1W() const{
    return std::round(_texture.getSize().x / _cols);
}

const float SpriteSheetCutter::get1H() const{
    return std::round(_texture.getSize().y / _rows);
}