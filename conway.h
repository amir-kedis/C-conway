#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 800
#define CELL_SIZE 10

void initwindow();
void randomize_grid(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);
void draw_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);

int count_neighbors(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE], int x,
    int y);

void update_cell(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE],
                 int x, int y);

void update_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);

Color get_cell_color(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE], int x,
    int y);

void handleClick(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);

void drawGridLines(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);
