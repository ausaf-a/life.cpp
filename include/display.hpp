#ifndef display_hpp
#define display_hpp

#include <SFML/Graphics.hpp> 
#include "life.hpp"

class Display{
public: 
    Display(int gw, int gh, int r, const std::string &title); 
    ~Display(); 
    void update(); 
    void handleEvents(); 
    bool isOpen() {return window.isOpen(); }; 
private: 
    Life life; 
    sf::RenderWindow window; 
    sf::RectangleShape square; 
    bool running; 
    int rows, cols, size;
    bool mouseInWindow(); 
    sf::Vector2i mouseGridPosition(); 
    void handleMouseDrag();
    void handleMouseRightClick();
}; 

#endif