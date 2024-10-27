#ifndef VIEW_H
#define VIEW_H

#include "../helper/helper.h"
#include "../mine_solver/mine_solver.h"

class View{
private:
    // sf::RenderWindow window;
    // sf::Font font;                      //font to draw on main screen
    // sf::Text myTextLabel;               //text to draw on main screen
    
public:
    View(){
        init();
    };
    void init();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
};

void View::run()
{
    std::cout<<std::endl<<"-------ANIMATE MAIN START ------------"<<std::endl;
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   std::cout<<std::endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<std::endl;
}

void View::render(){
    window.clear(sf::Color::Black);

    Draw();
    window.display();
}

void View::update(){
}

void View::processEvents(){
    sf::Event e;
    while(window.pollEvent(e)){
        if(e.type == sf::Event::Closed) {
            window.close();
        }

        if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space) {
            minesweeperOperations(map, GRID_Y, GRID_X);    
        }

        if(e.type == sf::Event::MouseButtonPressed){
            int x = (int)(e.mouseButton.x / CELL_SIZE);
            int y = (int)(e.mouseButton.y / CELL_SIZE);

            if(x < GRID_X && x >= 0 && y < GRID_Y && y >=0){
                if(e.mouseButton.button == sf::Mouse::Right){
                    if(map_view[y][x] != 9 && map_view[y][x] == 10){ // 9 - flag
                        map_view[y][x] = 9;
                    }
                    else if (map_view[y][x] == 9){
                        map_view[y][x] = 10;
                    }
                }
                if(e.mouseButton.button == sf::Mouse::Left){
                    map_view[y][x] = map[y][x];
                    if(map[y][x] == 0){
                        open_all_zero_around(x,y);
                    }
                    if(map[y][x] == -1){
                        display_mine();

                        SpriteSheetCutter mineL(texture, 12, 12);
                        mineL.set(0,6);
                        mineL.scale((float)CELL_SIZE/(float)mineL.get1W(),(float)CELL_SIZE/(float)mineL.get1H());
                        mineL.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
                        window.draw(mineL);

                        std::string t = "Game Over!";
                        game_over(t);
                        return;
                    }
                    check_win();
                }
            }
        }
    }
}

void View::Draw(){
    //draw
    window.clear(sf::Color::Black);
    for(int y=0; y< GRID_Y; y++){
        for(int x=0; x< GRID_X; x++){                            
            //draw square  
            SpriteSheetCutter cell(texture, 12, 12);
            cell.set(0,0);
            cell.scale((float)CELL_SIZE/(float)cell.get1W(),(float)CELL_SIZE/(float)cell.get1H());
            cell.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
            window.draw(cell);

            if(map_view[y][x]==-1){
                //draw mine
                SpriteSheetCutter mine(texture, 12, 12);
                mine.set(0,5);
                mine.scale((float)CELL_SIZE/(float)mine.get1W(),(float)CELL_SIZE/(float)mine.get1H());
                mine.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
                window.draw(mine);
            } 
            
            else if (map_view[y][x] == 9){
                SpriteSheetCutter flag(texture, 12, 12);
                flag.set(0,2);
                flag.scale((float)CELL_SIZE/(float)flag.get1W(),(float)CELL_SIZE/(float)flag.get1H());
                flag.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
                window.draw(flag);
            } 
            
            else if(map_view[y][x]!= 10) {
                SpriteSheetCutter number(texture, 12, 12);
                int n_bomb = map[y][x] - 1;
                number.set(1,n_bomb); // Output 1 and above

                if(map[y][x] == 0){
                    number.set(0,1); // Output blank
                }

                number.scale((float)CELL_SIZE/(float)number.get1W(),(float)CELL_SIZE/(float)number.get1H());
                number.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
                window.draw(number);   
            }
        }
    }
}

void View::init(){
    initTextures();
    initFont();
}



#endif