#include "display.hpp"
#include "config.hpp"

Display::Display(int gw, int gh, int r, const std::string &title) : window(sf::VideoMode(gw * r, gh * r), title),
                                                                    square(sf::Vector2f(r, r)),
                                                                    life(gw, gh) {
    this->rows = gh;
    this->cols = gw;
    this->size = r;
    running = false;
    square.setOutlineColor(COLOR_BORDER); 
    square.setOutlineThickness(1.0f); 
}

Display::~Display(){

}

void Display::update() {
    window.clear(sf::Color::Black);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            square.setPosition(sf::Vector2f(x * size, y * size));
            square.setFillColor(life.getCell(x, y) == 0 ? COLOR_DEAD : COLOR_ALIVE);
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
            // std::cout << "mousemove" << std::endl; 
            if (mouseInWindow() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                handleMouseLeftClick();
            }
            else if (mouseInWindow() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                handleMouseRightClick();
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
                case sf::Keyboard::R:
                    running = false;
                    life.reset(); 
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

void Display::handleMouseLeftClick() {
    sf::Vector2i m = mouseGridPosition();
    life.setCell(m.x, m.y, 1);
}

void Display::handleMouseRightClick() {
    sf::Vector2i m = mouseGridPosition();
    life.setCell(m.x, m.y, 0);
}

sf::Vector2i Display::mouseGridPosition() {
    sf::Vector2i m = sf::Mouse::getPosition(window);
    int x = m.x / size;
    int y = m.y / size;
    return sf::Vector2i(x, y);
}


