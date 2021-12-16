#include "Game.h"
#include <raylib.h>
#include <iostream>

int main(){
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int FPS = 60;
    
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT, 60, "hello");

    while (!game.GameShouldClose()){
        game.Tick();
    }
    return 0;
}

// run program: cc main.cpp Game.cpp Board.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lstdc++; ./a.out