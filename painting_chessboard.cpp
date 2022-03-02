#include <iostream>


int main() {
    int height, width;
    std::cin >> height >> width;

    char **board = initializeBoard(height, width);
    char **scoreboard = initializeBoard(height, width);

    inputBoardColor(board, height, width);

    deleteBoard(board, height);
    deleteBoard(scoreboard, height);
    return 0;
}

char** initializeBoard(int height, int width) {
    char **board = new char* [height];
    for (int i = 0; i < height; ++i) {
        board[i] = new char[width];
    }
    return board;
}

void deleteBoard(char** board, int height) {
    for (int i = 0; i < height; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void inputBoardColor(char** board, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cin >> board[i][j];
        }
    }
}

void calculateScore(char** board, char** scoreboard, int height, int width) {
    
}