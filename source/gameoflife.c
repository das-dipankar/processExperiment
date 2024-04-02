#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20
#define STEPS 100

void initializeGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2; // Randomly initialize cells
        }
    }
}

void printGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x] ? 'O' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                count += grid[ny][nx];
            }
        }
    }
    return count;
}

void updateGrid(int current[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int liveNeighbors = countNeighbors(current, x, y);
            if (current[y][x] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                next[y][x] = 0;
            } else if (current[y][x] == 0 && liveNeighbors == 3) {
                next[y][x] = 1;
            } else {
                next[y][x] = current[y][x];
            }
        }
    }
}

int main() {
    int currentGrid[HEIGHT][WIDTH], nextGrid[HEIGHT][WIDTH];
    
    initializeGrid(currentGrid);
    
    for (int step = 0; step < STEPS; step++) {
        system("clear"); // Use "cls" on Windows
        printGrid(currentGrid);
        updateGrid(currentGrid, nextGrid);
        
        // Copy nextGrid to currentGrid
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                currentGrid[y][x] = nextGrid[y][x];
            }
        }
        
        usleep(100000); // Slow down the simulation
    }
    
    return 0;
}
