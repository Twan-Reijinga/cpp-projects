#include <iostream>
#include <vector>
#include <string>

int getInput() {
    int input;
    if (std::cin >> input && input > 0) {
        return input;
    }
    throw std::runtime_error("\nerror: invalid input");
}

std::vector < std::vector < std::vector<bool> > > create3DBoard(int N) {
    return std::vector < std::vector < std::vector<bool> > > (N, std::vector < std::vector<bool> >(N, std::vector<bool>(N, false)));
}

bool in2DConflict(std::vector < std::vector <bool> >& board, int y, int x) {
    for (int i = 1; i <= y; i++) {
        if (board.at(y-i).at(x)) { return true; }
        if(x-i >= 0 && board.at(y-i).at(x-i)) { return true; } 
        if(x+i < board.size() && board.at(y-i).at(x+i)) { return true; }
    }
    return false;
}

bool in3DConflict(std::vector < std::vector < std::vector <bool> > >& board, int z, int y, int x) {
    int N = board.size();
    for (int i = 1; i <= z; i++) {
        if(x-i >= 0 && board.at(z-i).at(y).at(x-i)) { return true; }
        if(board.at(z-i).at(y).at(x)) { return true; }
        if(x+i < N && board.at(z-i).at(y).at(x+i)) { return true; }
        if(y-i >= 0) {
            if(x-i >= 0 && board.at(z-i).at(y-i).at(x-i)) { return true; }
            if(board.at(z-i).at(y-i).at(x)) { return true; }
            if(x+i < N && board.at(z-i).at(y-i).at(x+i)) { return true; }
        }
        if(y+i < N) {
            if(x-i >= 0 && board.at(z-i).at(y+i).at(x-i)) { return true; }
            if(board.at(z-i).at(y+i).at(x)) { return true; }
            if(x+i < N && board.at(z-i).at(y+i).at(x+i)) { return true; }
        }
    }
    return false;
}

bool inConflict(std::vector < std::vector < std::vector <bool> > >& board, int z, int y, int x) {
    if(in2DConflict(board.at(z), y, x) || in3DConflict(board, z, y, x)) {
        return true;
    }
    return false;
}

bool placeQueens(int N, std::vector < std::vector < std::vector<bool> > >& board, int z, int y) {
    if (y == N) {
        y = 0;
        z++;
    }
    if (z == N) {
        return true;
    }
    // for (int i = 0; i < N; i++) {
    for (int x = 0; x < N; x++) {
        if(!inConflict(board, z, y, x)) {
            board.at(z).at(y).at(x) = true;
            if (placeQueens(N, board, z, y+1)) {
                return true;
            }
            board.at(z).at(y).at(x) = false;
        }
    }
    // }
    return false;
}

void printBoard(const std::vector < std::vector < std::vector<bool> > >& board) {
    int N = board.size();
    std::cout << std::endl;
    for (int i = 0; i < N; i++) { // board.size()
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (board.at(i).at(j).at(k)) {
                    std::cout << "Q";
                } else {
                    std::cout << "_";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
}

int main() {
    try {
        std::cout << "How many queens to place on the board? ";
        int N = getInput();
        std::vector < std::vector < std::vector<bool> > > board = create3DBoard(N);
        if(placeQueens(N, board, 0, 0)) {
            printBoard(board);
        } else {
            const std::string n = std::to_string(N);
            throw std::runtime_error("\nNo solution found to place " + n + " queens on a " + n + " by " + n + " chess board");
        }
    } catch (std::runtime_error &e) { 
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
