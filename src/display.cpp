#include "display.hpp"
#include <iostream>

Display::Display(int gw, int gh, int r, const std::string &title) : window(sf::VideoMode(gw * r, gh * r), title),
                                                                    square(sf::Vector2f(r, r)),
                                                                    life(gw, gh) {
    this->rows = gw;
    this->cols = gh;
    this->size = r;
    running = false;
    square.setFillColor(sf::Color::White);
    square.setOutlineThickness(1.0f);
    square.setOutlineColor(sf::Color::Black);
}

Display::~Display(){

}

void Display::update() {
    window.clear(sf::Color::Black);

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            square.setPosition(sf::Vector2f(x * size, y * size));
            square.setFillColor(life.getCell(x, y) == 0 ? sf::Color::White : sf::Color::Red);
            window.draw(square);
        }
    }

    if (running) {
        life.update();
    }
    window.display(); 
}

void Display::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseMoved) {
            if (mouseInWindow() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                handleMouseDrag();
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Space:
                    running = !running;
                    break;
                default:
                    break;
            }
        }
    }
}

bool Display::mouseInWindow() {
    sf::Vector2i m = sf::Mouse::getPosition(window);
    int x = m.x / size;
    int y = m.y / size;
    return (x >= 0 && x < cols && y >= 0 && y < rows);
}

void Display::handleMouseDrag() {
    sf::Vector2i m = mouseGridPosition();
    std::cout << m.x << "," << m.y << std::endl; 
    life.setCell(m.x, m.y, 1);
}

sf::Vector2i Display::mouseGridPosition() {
    sf::Vector2i m = sf::Mouse::getPosition(window);
    int x = m.x / size;
    int y = m.y / size;
    return sf::Vector2i(x, y);
}
