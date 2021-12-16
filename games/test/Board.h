#include <raylib.h>
#include <vector>

class Board {
    public:
        Board(int screenX, int screenY, int width, int height, int cellSize);
        void Draw() const;
    private:
};