#include "Game.h"
#include <raylib.h>
#include <assert.h>

Game::Game(int width, int height, int fps, std::string title) 
: board(200, 200, 10, 20, 15)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
    assert(GetWindowHandle()); // If assertion triggers : Window already closed
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
    ClearBackground(BLACK);
    board.Draw();
}



