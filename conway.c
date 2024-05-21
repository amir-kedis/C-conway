#include "conway.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Conway's Game of Life
 *
 * conway in C with raylib baby.
 */
int main() {
  initwindow();

  int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE] = {0};

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    if (IsKeyPressed(KEY_R)) {
      randomize_grid(grid);
    }

    draw_grid(grid);

    EndDrawing();
  }
}

void initwindow() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Conway's Game of Life");
  SetTargetFPS(60);
}

void randomize_grid(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      grid[i][j] = GetRandomValue(0, 1);
    }
  }
}

void draw_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]) {
  for (int i = 0; i < SCREEN_WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / CELL_SIZE; j++) {
      if (grid[i][j] == 1) {
        DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                      WHITE);
      }
    }
  }
}
