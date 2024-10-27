#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "../Constant/window-constant.h"

class Board : public sf::Drawable
{
private:
    std::vector<std::vector<SpriteSheetCutter>> _board;
    void init();
    int _rows, _cols;
    sf::Texture &_texture;

public:
    Board(sf::Texture &texture, int rows, int cols);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif //SPRITESHEETCUTTER_H
