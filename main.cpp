#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

// #include "./includes/grid/grid.h"
#include "./includes/View/view.h"
// #include "./includes/Controller/Controller.h"
#include "./includes/mine_solver/mine_solver.h"

int main(int argc, char *argv[])
{    
    // Controller c;
    View v;
    generateMineField(GRID_Y, GRID_X, MINE_P);
    v.run();

    // generate_map();
    // minesweeperOperations(map, GRID_Y, GRID_X); 

    std::cout<<"------ NORMAL TERMINATION: WINDOW CLOSED!"<<std::endl;
    return 0;
}



















