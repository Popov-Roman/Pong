#include "Game.cpp"
#include "Field.cpp"
#include <Windows.h>

void print_field(Field& f);
void update_field(Game& g);

bool strelka_vpravo() {
    SHORT state = GetKeyState(68);
    if (state < 0) {
        return false;
    }
    else if (state > 0) {
        return true;
    }
    else {
        return false;
    }
};

bool strelka_vlevo(){
    SHORT state = GetKeyState(65);
    if (state < 0) {
        return false;
    }
    else if (state > 0) {
        return true;
    }
    else {
        return false;
    }
};
