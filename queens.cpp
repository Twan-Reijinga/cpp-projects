#include <iostream>
#include <string>
#include <vector>

int getInput() {
    int input;
    if (std::cin >> input && input > 0) {
        return input;
    }
    throw std::runtime_error("\nerror: invalid input");
}

bool inConflict(int N, const std::vector < std::vector <bool> >& board, int row, int col) {
    for (int i = 1; i <= row; i++) {
        if (board.at(row-i).at(col)) return true;
        if (col-i >= 0 && board.at(row-i).at(col-i)) return true; 
        if (col+i < N && board.at(row-i).at(col+i)) return true;
    }
    return false;
}

bool placeQueens(int N, std::vector < std::vector <bool> >& board, int row) {
    if (row >= N) return true;
    for (int i = 0; i < N; i++) {
        if(!inConflict(N, board, row, i)) {
            board.at(row).at(i) = true;
            if (placeQueens(N, board, row+1)) return true;
            board.at(row).at(i) = false;
        }
    }
    return false;
}

void printBoard(const std::vector < std::vector <bool> >& board) {
    std::cout << std::endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board.at(i).at(j)) {
                std::cout << "Q";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    try {
        std::cout << "How many queens to place on the board? ";
        int N = getInput();
        std::vector < std::vector<bool> > board(N, std::vector<bool>(N, false));
        if(placeQueens(N, board, 0)) {
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
