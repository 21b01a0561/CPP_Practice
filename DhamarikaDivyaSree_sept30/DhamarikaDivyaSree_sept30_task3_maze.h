#ifndef MAZE_H
#define MAZE_H

const int SIZE = 12;

// Function prototypes
void printMaze(char maze[SIZE][SIZE]);
bool mazeTraverse(char maze[SIZE][SIZE], int x, int y, int direction, int startX, int startY);

#endif
