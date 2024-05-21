
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800
#define CELL_SIZE 10

void initwindow();
void randomize_grid(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);
void draw_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);

void count_neighbors(
    int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);

void update_grid(int grid[SCREEN_WIDTH / CELL_SIZE][SCREEN_HEIGHT / CELL_SIZE]);
