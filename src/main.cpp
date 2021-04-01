#include <SFML/Graphics.hpp>
#include <array>
#include <cstdlib>
#include <iostream>

#include "display.hpp"

#define GRID_SIZE 20
#define WIDTH GRID_WIDTH * GRID_SIZE
#define HEIGHT GRID_HEIGHT * GRID_SIZE
#define DELAY 10

int main(int argc, char **argv) {
    Display display(50,50,10,"Conway's Game of Life");

    while (display.isOpen()) {
        display.handleEvents(); 
        display.update();
    }

    return 0;
}
