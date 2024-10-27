#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

#include "../View/View.h"
#include "../helper/helper.h"

class Controller{
    private:
        View *v;

    public:
        Controller();

        
        bool isValid(int y, int x);
        void generateMineField(int COL, int ROW, int P);
        void printGrid(bool grid[GRID_Y][GRID_X]);
        bool isSafe(int map[GRID_Y][GRID_X], int y, int x);
        bool findUnvisited(bool visited[GRID_Y][GRID_X], int& y, int& x);
        bool isDone(int map[GRID_Y][GRID_X], bool visited[GRID_Y][GRID_X]);
        bool SolveMinesweeper(bool grid[GRID_Y][GRID_X], int map[GRID_Y][GRID_X],bool visited[GRID_Y][GRID_X]);
        void minesweeperOperations(int map[GRID_Y][GRID_X], int N,int M);
        bool SolveMinesweeperStep(bool grid[GRID_Y][GRID_X], int map[GRID_Y][GRID_X], bool visited[GRID_Y][GRID_X], int& currentY, int& currentX);
};

bool solverRunning = false;
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { 0, 0, 0, -1, -1, -1, 1, 1, 1 };

bool Controller::isValid(int y, int x)
{
    return (y >= 0 && x >= 0
            && y < GRID_Y && x < GRID_X);
}

void Controller::generateMineField(int COL, int ROW, int P)
{ 
    int rand_val;
    int mines[COL][ROW];

    for (int y = 0; y < COL; y++) {
        for (int x = 0; x < ROW; x++) {
            rand_val = random(0,100) % 100;
             if (rand_val < P)
                 mines[y][x] = true;
            else
                mines[y][x] = false;
        }
    }
 
    std::cout << "Generated Input:\n";
 
    // Iterate through each cell (y, x)
    for(int y = 0; y < COL; y++){
        for(int x = 0; x < ROW; x++){
            map[y][x] = 0;
            for (int k = 0; k < 9; k++) {
                if (isValid(
                    y + dy[k], x + dx[k])
                    && (mines[y + dy[k]][x + dx[k]]))
                    map[y][x]++;
            }
             std::cout << map[y][x] << " ";
        }
        std::cout << std::endl;
    }
    // set_numbers();
}

void Controller::printGrid(bool grid[GRID_Y][GRID_X])
{
	for (int col = 0; col < GRID_Y; col++) {
		for (int row = 0; row < GRID_X; row++) {
			if (grid[col][row]){
				map_view[col][row] = 9;                
                std::cout << "x ";
                }
			else{
				std::cout << "_ ";}
		}
		std::cout << std::endl;
	}
}

bool Controller::isSafe(int map[GRID_Y][GRID_X], int y, int x)
{
	if (!isValid(y, x))
		return false;

	for (int i = 0; i < 9; i++) {
		if (isValid(y + dy[i],x + dx[i])
			&& (map[y + dy[i]][x + dx[i]] - 1 < 0))
			return (false);
	}

	for (int i = 0; i < 9; i++) {
		if (isValid(y + dy[i],x + dx[i]))
			map[y + dy[i]][x + dx[i]]--;
	}

	return true;
}

bool Controller::findUnvisited(bool visited[GRID_Y][GRID_X], int& y, int& x)
{
    for (y = 0; y < GRID_Y; y++)
	    for (x = 0; x < GRID_X; x++)
			if (!visited[y][x])
				return (true);
	return (false);
}

bool Controller::isDone(int map[GRID_Y][GRID_X], bool visited[GRID_Y][GRID_X])
{
	bool done = true;
	for (int y = 0; y < GRID_Y; y++) {
	    for (int x = 0; x < GRID_X; x++) {
			done
				= done && (map[y][x] == 0) && visited[y][x];
		}
	}
	return (done);
}

bool Controller::SolveMinesweeper(bool grid[GRID_Y][GRID_X],
					int map[GRID_Y][GRID_X],
					bool visited[GRID_Y][GRID_X])
{
	bool done = isDone(map, visited);

	if (done)
		return true;

	int x, y;

	if (!findUnvisited(visited, y, x))
		return false;

	visited[y][x] = true;
	if (isSafe(map, y, x)) {
		grid[y][x] = true;
		if (SolveMinesweeper(grid, map, visited))
			return true;
		grid[y][x] = false;
		for (int i = 0; i < 9; i++) {
			if (isValid(y + dy[i],x + dx[i]))
				map[y + dy[i]][x + dx[i]]++;
		}
	}

	if (SolveMinesweeper(grid, map, visited))
		return true;

	visited[y][x] = false;
	return false;
}

void Controller::minesweeperOperations(int map[GRID_Y][GRID_X], int N,
						int M)
{

	// Stores the final result
	bool grid[GRID_Y][GRID_X];

	bool visited[GRID_Y][GRID_X];

	memset(grid, false, sizeof(grid));
	memset(visited, false, sizeof(visited));

	if (SolveMinesweeper(grid, map, visited)) {

		// Function call to print the grid[][]
		printGrid(grid);
	}

	else
		printf("No solution exists\n");
}

#endif