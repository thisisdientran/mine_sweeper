// #include "helper.h"

// int random(int min, int max){
//     static bool first = true;
//     if (first){
//         srandom(time(NULL));
//         first = false;
//     }
//     return min + rand() % (max - min + 1);
// }

// void set_map();
// void set_numbers(){
//     for(int y = 0; y < GRID_Y; y++){
//         for(int x = 0; x < GRID_X; x++){
//             map_view[y][x] = 10;
//             if(map[y][x] != -1){
//                 int n = 0;
//                 for (auto i : ways){
//                     if(x - i[0] >= 0 && x - i[0] < GRID_X && y - i[1] >= 0 && y - i[1] < GRID_Y && map[y-i[1]][x-i[0]] == -1){
//                         n++;
//                     }
//                 }
//                 map[y][x] = n;
//                 // std::cout << map[y][x] << " ";
//             }
//         }
//     }
// };

// void open_all_zero_around(int x, int y){
//     for(auto i : ways){
//         if(x - i[0] >= 0 && x - i[0] < GRID_X && y - i[1] >= 0 && y - i[1] < GRID_Y && (map_view[y-i[1]][x-i[0]] == 10)){
//             map_view[y-i[1]][x-i[0]] = map[y-i[1]][x-i[0]];
//             if(map[y-i[1]][x-i[0]] == 0){
//                 open_all_zero_around(x - i[0],y - i[1]);
//             }
//         }
//     }
// }

// void generate_map(){
//     for(int y = 0; y < GRID_Y; y++){
//         for(int x = 0; x < GRID_X; x++){
//             map[y][x] = 10;
//             if(random(0,5) == 1){
//                 map[y][x] = -1;
//             } else {
//                 map[y][x] = 0;
//             }
//             // std::cout << map[y][x] << " ";
//         }
//     }
//     set_numbers();
// }

// void game_over(std::string t){
//     sf::Text text;
//     text.setFont(font);
//     text.setString(t);
//     text.setFillColor(sf::Color::Red);
//     text.setCharacterSize(std::min(SCREEN_X, SCREEN_Y)/4);
//     window.draw(text);
//     window.display();
//     sf::Event e;
//     while(1){
//         while(window.pollEvent(e)){
//             if(e.type == sf::Event::Closed){
//                 return;
//             }
//         }
//     }
// }

// void check_win(){
//     for(int y = 0; y < GRID_Y; y++){
//         for(int x = 0; x < GRID_X; x++){
//             std::cout
//                 << ", map: " << map[y][x] 
//                 << ", map_view: " << map_view[y][x]
//                 <<  std::endl;

//             if(!(map[y][x] == map_view[y][x] 
//             || (map[y][x] == -1 && map_view[y][x] == 9)
//             || map[y][x] == 0 && map_view[y][x] == 10)){
//                 std::cout << "No win" 
//                 << ", map: " << map[y][x] 
//                 << ", map_view: " << map_view[y][x]
//                 <<  std::endl;
//                 return;
//             }
//         }
//     }
//     std::string t = "You won!";
//     std::cout << t << std::endl;
//     game_over(t);
//     return;
// }

// void display_mine(){
//     for(int y = 0; y < GRID_Y; y++){
//         for(int x = 0; x < GRID_X; x++){
//             if(map[y][x]==-1){
//                 //draw mine
//                 SpriteSheetCutter mine(texture, 12, 12);
//                 mine.set(0,5);
//                 mine.scale((float)CELL_SIZE/(float)mine.get1W(),(float)CELL_SIZE/(float)mine.get1H());
//                 mine.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
//                 window.draw(mine);
//             }
//         }
//     }
// }
