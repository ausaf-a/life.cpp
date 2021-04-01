#include "life.hpp"

Life::Life(int rows, int cols): grid(cols, std::vector<int>(rows, 0)), next(cols, std::vector<int>(rows, 0)) {
   this->rows = rows; 
   this->cols = cols;  
}

Life::~Life() {
}

void Life::update() {
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            if (y < rows - 1) {
                next[y + 1][x] = grid[y][x]; 
            }
        }
    }
    std::swap(grid, next);
}

void Life::setCell(int x, int y, int value) {
    if (x >= 0 && x < cols && y >= 0 && y < rows)
        grid[y][x] = value; 
}

int Life::getCell(int x, int y) {
    return grid[y][x]; 
}

std::vector<std::vector<int>> Life::getWorld(){
    return this->grid; 
}

void Life::reset() {
    for (auto &row : grid)
        std::fill(row.begin(), row.end(), 0); 

    for (auto &row : next)
        std::fill(row.begin(), row.end(), 0); 
}