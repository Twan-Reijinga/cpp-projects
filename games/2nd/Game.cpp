#include "Game.h"
#include <raylib.h>

Game::Game(int width, int height, std::string title) {
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
    CloseWindow();
}

bool Game::GameShouldClose() const {
    return WindowShouldClose();
}

void Game::Tick() {
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Update() {
    
}

void Game::Draw() {

}


