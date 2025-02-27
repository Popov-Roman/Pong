#include <iostream>
#include <iomanip>

class Field {
public:
    class Ball {
    public:
        float x, y;
        float v_x, v_y;

        Ball(float startX, float startY) : x(startX), y(startY), v_x(0), v_y(0) {}
    };

    class Poe {
    public:
        float max_speed;
        float width;
        float v_x;
        float x;

        Poe(float startX, float startWidth) : x(startX), width(startWidth), max_speed(5.0f), v_x(0) {}
    };

    int width;
    int height;
    Ball ball;
    Poe poe;

    Field(int w, int h) : width(w), height(h), ball(0, 0), poe(0, 10) {}

    void display() {
        for (int i = 0; i < width; i++){
            std::cout << "=";
        };
        std::cout << std::endl;
        for (int y = height - 1; y >= 0; --y){
            for (int x = 0; x < width; ++x){
                std::cout << "|";
                if (static_cast<int>(ball.x) == x && static_cast<int>(ball.y) == y) {
                    std::cout << "@";
                } 
                else if (static_cast<int>(poe.x) <= x && x < static_cast<int>(poe.x + poe.width) && y == 0) {
                    std::cout << "#";
                } 
                else {
                    std::cout << "[]";
                }
                std::cout << "|";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < width; i++) {
            std::cout << "=";
        };
    }
};