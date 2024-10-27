// #include "board.h"

// Board::Board(sf::Texture &texture, int rows, int cols)
//     : _texture(texture), _rows(rows), _cols(cols)
// {
//     init();
// }

// void Board::init(){
//     for(int i=0; i<_rows; i++){
//         for(int j=0; j<_cols; j++){
//             _board[i][j].set(i,j);
//         }
//     }
// }

// void Board::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//     for (int i = 0; i < _rows; ++i) {
//         for (int j = 0; j < _cols; ++j) {
//             window.draw(_board[i][j], states);  // Assuming SpriteSheetCutter has its own drawable
//         }
//     }
// }

