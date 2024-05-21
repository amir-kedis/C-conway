/* ==========================================================================
 * conway.c
 * ==========================================================================
 * Conway's Game of Life
 * made by Amir because he is bored and doesn't want to study for his exams.
 * ==========================================================================
 */

#include "conway.h"
#include <raylib.h>

/**
 * Conway's Game of Life
 *
 * conway in C with raylib baby.
 */
int main() {
  initwindow();

  int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE] = {0};
  int running = true;
  int gridLines = false;

  randomize_grid(grid);

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (IsKeyPressed(KEY_R)) {
      randomize_grid(grid);
    }

    if (IsKeyPressed(KEY_SPACE)) {
      running = !running;
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
      break;
    }

    if (IsKeyPressed(KEY_G)) {
      gridLines = !gridLines;
    }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      handleClick(grid);
    }

    ClearBackground(BLACK);

    if (gridLines) {
      drawGridLines(grid);
    }
    draw_grid(grid);

    if (!running) {
      EndDrawing();
      continue;
    }

    update_grid(grid);
    WaitTime(0.1);

    EndDrawing();
  }
}

/** initwindow - Initialize the window */
void initwindow() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Conway's Game of Life");
  SetTargetFPS(60);
}

/**
 * randomize_grid - Randomize the grid
 * @grid: The grid to randomize
 */
void randomize_grid(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      grid[i][j] = GetRandomValue(0, 1);
    }
  }
}

/**
 * draw_grid - Draw the grid
 * @grid: The grid to draw
 */
void draw_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      if (grid[i][j] == 1) {
        DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                      get_cell_color(grid, i, j));
      }
    }
  }
}

/*
 *
 * /*
background: rgba(114, 20, 38, 1.0);
background: linear-gradient(135deg, rgba(114, 20, 38, 1.0), rgba(95, 108,
211, 1.0));
*/

/**
 * get_cell_color - give the cell a unique color based on the count of neighbors
 * @grid: The grid to get the color
 * @x: The x coordinate
 * @y: The y coordinate
 */
Color get_cell_color(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE], int x,
    int y) {
  int count = count_neighbors(grid, x, y);

  Color col = {0, 0, 0, 0};

  switch (count) {
  case 0:
  case 1:
    col = (Color){95, 108, 211, 255};
    break;
  case 2:
    col = (Color){100, 80, 134, 255};
    break;
  case 3:
    col = (Color){104, 60, 102, 255};
    break;
  case 4:
    col = (Color){108, 40, 70, 255};
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  default:
    col = (Color){114, 20, 38, 255};
    break;
  }

  return col;
}

/**
 * count_neighbors - Count the number of neighbors
 * @grid: The grid to count the neighbors
 * @x: The x coordinate
 * @y: The y coordinate
 *
 * Return: The number of neighbors
 */
int count_neighbors(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE], int x,
    int y) {
  int count = 0;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      int row = (x + i + SCREEN_WIDTH / CELL_SIZE) % (SCREEN_WIDTH / CELL_SIZE);
      int col =
          (y + j + SCREEN_HEIGHT / CELL_SIZE) % (SCREEN_HEIGHT / CELL_SIZE);
      count += grid[row][col];
    }
  }

  return count;
}

/**
 * update_grid - Update the grid
 * @grid: The grid to update
 */
void update_grid(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  int new_grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE] = {0};

  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      int neighbors = count_neighbors(grid, i, j);

      if (neighbors < 2)
        new_grid[i][j] = 0;
      else if (neighbors == 3)
        new_grid[i][j] = 1;
      else if (neighbors > 3)
        new_grid[i][j] = 0;
      else
        new_grid[i][j] = grid[i][j];
    }
  }

  memcpy(grid, new_grid, sizeof(new_grid));
}

/**
 * handleClick - Handle the mouse click
 * @grid: The grid to handle the click
 */
void handleClick(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  Vector2 mouse = GetMousePosition();
  int x = mouse.x / CELL_SIZE;
  int y = mouse.y / CELL_SIZE;

  grid[x][y] = 1;
}

/**
 * drawGridLines - Draw the grid lines
 * @grid: The grid to draw the lines
 */
void drawGridLines(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      DrawRectangleLines(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                         ColorAlpha(get_cell_color(grid, i, j), 0.2));
    }
  }
}
