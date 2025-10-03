#include "maze.h"
#include <iostream>


// Directions: 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// Print maze after each move
void printMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------\n";
}

// Recursive Maze Traversal using right-hand rule
bool mazeTraverse(char maze[SIZE][SIZE], int x, int y, int direction, int startX, int startY) {
    maze[x][y] = 'X';  // Mark current position
    printMaze(maze);

    // Base case: reached exit (at border and not starting position)
    if ((x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1) && !(x == startX && y == startY)) {
        std::cout << "Exit found at (" << x << "," << y << ")" << std::endl;
        return true;
    }

    // Try to turn right first
    int newDir = (direction + 1) % 4;
    int nx = x + dx[newDir], ny = y + dy[newDir];
    if (maze[nx][ny] == '.') {
        if (mazeTraverse(maze, nx, ny, newDir, startX, startY)) 
           return true;
    }

    // Try to go straight
    nx = x + dx[direction]; ny = y + dy[direction];
    if (maze[nx][ny] == '.') {
        if (mazeTraverse(maze, nx, ny, direction, startX, startY)) 
           return true;
    }

    // Try to turn left
    newDir = (direction + 3) % 4;
    nx = x + dx[newDir]; ny = y + dy[newDir];
    if (maze[nx][ny] == '.') {
        if (mazeTraverse(maze, nx, ny, newDir, startX, startY)) 
            return true;
    }

    // Try to turn back
    newDir = (direction + 2) % 4;
    nx = x + dx[newDir]; ny = y + dy[newDir];
    if (maze[nx][ny] == '.') {
        if (mazeTraverse(maze, nx, ny, newDir, startX, startY)) 
            return true;
    }

    // No moves possible, backtrack
    return false;
}
