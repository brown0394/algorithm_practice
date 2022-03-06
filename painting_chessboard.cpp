#include <iostream>

char** initializeBoard(int height, int width);
void deleteBoard(char** board, int height);
void inputBoardColor(char** board, int height, int width);
void calculateScore(char** board, char** scoreboard, int height, int width);

int main() {
    int height, width;
    std::cin >> height >> width;

    char **board = initializeBoard(height, width);
    char **scoreboard = initializeBoard(height, width);

    inputBoardColor(board, height, width);

    calculateScore(board, scoreboard, height, width);

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
    int best = -1;
    bool white = false;

    for (int i = 0; i < height - 7; ++i) {
        for (int j = 0; j < width - 7; ++i) {
            int score = 0;
            for (int k = i; k < 8; ++k) {
                for (int l = j; l < 8; ++l) {
                    if (k == i && j == l) {
                        if (scoreboard[k][l] == 'b') white = false;
                        else white = true;
                    }
                    if ((scoreboard[k][l] == 'b' && white == true) ||
                    (scoreboard[k][l] == 'w' && white == false)) {
                        ++score;
                    }
                    if (white) white = false;
                    else white = true;
                }
                if (white) white = false;
                else white = true;
            }
            if (best == -1 || score < best) best = score;
        }
    }
    std::cout << best << std::endl;
}