#include <iostream>
#include "display.hpp"

#define GRID_SIZE 20
#define WIDTH GRID_WIDTH * GRID_SIZE
#define HEIGHT GRID_HEIGHT * GRID_SIZE
#define DELAY 100

int main(int argc, char **argv) {
    Display display(30,20,20,"Conway's Game of Life");

    std::cout << "Drag using the left mouse button to edit cells" << std::endl; 
    std::cout << "Space:\tToggle play/pause" << std::endl; 
    std::cout << "R:\tReset world" << std::endl; 
    std::cout << "ESC:\tQuit" << std::endl; 

    while (display.isOpen()) {
        display.handleEvents(); 
        display.update();
        sf::sleep(sf::milliseconds(DELAY)); 
    }

    return 0;
}
