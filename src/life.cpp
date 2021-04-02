#include "life.hpp"

Life::Life(int cols, int rows) : grid(rows, std::vector<int>(cols, 0)), next(rows, std::vector<int>(cols, 0)) {
    this->rows = rows;
    this->cols = cols;
}

Life::~Life() {
}

void Life::update() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int n = 0;

            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (x + i >= 0 && x + i < cols && y + j >= 0 && y + j < rows) {
                        n += grid[y + j][x + i]; 
                    }
                }
            }
            n -= grid[y][x]; 

            if (grid[y][x]) {
                next[y][x] = (n < 2 || n > 3) ? 0 : 1;
            } else {
                next[y][x] = (n == 3) ? 1 : 0;
            }
        }
    }
    std::swap(grid, next);
}

void Life::setCell(int x, int y, int value) {
    grid[y][x] = value;
}

int Life::getCell(int x, int y) {
    return grid[y][x];
}

std::vector<std::vector<int>> Life::getWorld() {
    return this->grid;
}

void Life::reset() {
    for (auto &row : grid)
        std::fill(row.begin(), row.end(), 0);

    for (auto &row : next)
        std::fill(row.begin(), row.end(), 0);
}