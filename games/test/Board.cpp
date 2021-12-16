#include "Board.h"
#include <assert.h>

Board::Board(int screenX, int screenY, int width, int height, int cellSize) {
    // setup
}

void Board::Draw() const {
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}


