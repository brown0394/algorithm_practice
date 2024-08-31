#include <iostream>
#include <vector>
#include <bitset>

std::vector<std::vector<std::vector<int>>> boardState;
int boardSize;
int maxVal = 0;
std::vector<std::bitset<25>> updated;

void up(int step) {
    for (int i = 0; i < boardSize; ++i) {
        boardState[step][0][i] = boardState[step - 1][0][i];
    }
    updated[0] = 0;
    for (int i = 1; i < boardSize; ++i) {
        updated[i] = 0;
        for (int j = 0; j < boardSize; ++j) {
            boardState[step][i][j] = boardState[step - 1][i][j];
            if (!boardState[step][i][j]) continue;
            int idx = i - 1;
            while (idx >= 0 && !boardState[step][idx][j]) {
                boardState[step][idx][j] = boardState[step][idx + 1][j];
                boardState[step][idx + 1][j] = 0;
                --idx;
            }
            if (idx >= 0 && !updated[idx][j] && boardState[step][idx][j] == boardState[step][idx + 1][j]) {
                boardState[step][idx][j] <<= 1;
                boardState[step][idx + 1][j] = 0;
                updated[idx][j] = true;
                if (boardState[step][idx][j] > maxVal) maxVal = boardState[step][idx][j];
            }
        }
    }
}

void down(int step) {
    for (int i = 0; i < boardSize; ++i) {
        boardState[step][boardSize-1][i] = boardState[step - 1][boardSize - 1][i];
    }
    updated[0] = 0;
    for (int i = boardSize - 2; i >= 0; --i) {
        updated[i] = 0;
        for (int j = 0; j < boardSize; ++j) {
            boardState[step][i][j] = boardState[step - 1][i][j];
            if (!boardState[step][i][j]) continue;
            int idx = i + 1;
            while (idx < boardSize && !boardState[step][idx][j]) {
                boardState[step][idx][j] = boardState[step][idx - 1][j];
                boardState[step][idx - 1][j] = 0;
                ++idx;
            }
            if (idx < boardSize && !updated[idx][j] && boardState[step][idx][j] == boardState[step][idx - 1][j]) {
                boardState[step][idx][j] <<= 1;
                boardState[step][idx - 1][j] = 0;
                updated[idx][j] = true;
                if (boardState[step][idx][j] > maxVal) maxVal = boardState[step][idx][j];
            }
        }
    }
}

void left(int step) {
    for (int i = 0; i < boardSize; ++i) {
        boardState[step][i][0] = boardState[step - 1][i][0];
    }
    updated[0] = 0;
    for (int i = 1; i < boardSize; ++i) {
        updated[i] = 0;
        for (int j = 0; j < boardSize; ++j) {
            boardState[step][j][i] = boardState[step - 1][j][i];
            if (!boardState[step][j][i]) continue;
            int idx = i - 1;
            while (idx >= 0 && !boardState[step][j][idx]) {
                boardState[step][j][idx] = boardState[step][j][idx + 1];
                boardState[step][j][idx + 1] = 0;
                --idx;
            }
            if (idx >= 0 && !updated[idx][j] && boardState[step][j][idx] == boardState[step][j][idx + 1]) {
                boardState[step][j][idx] <<= 1;
                boardState[step][j][idx + 1] = 0;
                updated[idx][j] = true;
                if (boardState[step][j][idx] > maxVal) maxVal = boardState[step][j][idx];
            }
        }
    }
}

void right(int step) {
    for (int i = 0; i < boardSize; ++i) {
        boardState[step][i][boardSize - 1] = boardState[step - 1][i][boardSize - 1];
    }
    updated[0] = 0;
    for (int i = boardSize - 2; i >= 0; --i) {
        updated[i] = 0;
        for (int j = 0; j < boardSize; ++j) {
            boardState[step][j][i] = boardState[step - 1][j][i];
            if (!boardState[step][j][i]) continue;
            int idx = i + 1;
            while (idx < boardSize && !boardState[step][j][idx]) {
                boardState[step][j][idx] = boardState[step][j][idx - 1];
                boardState[step][j][idx - 1] = 0;
                ++idx;
            }
            if (idx < boardSize && !updated[idx][j] && boardState[step][j][idx] == boardState[step][j][idx - 1]) {
                boardState[step][j][idx] <<= 1;
                boardState[step][j][idx - 1] = 0;
                updated[idx][j] = true;
                if (boardState[step][j][idx] > maxVal) maxVal = boardState[step][j][idx];
            }
        }
    }
}

void tryDir(int step) {
    if (step == 5) return;
    up(step + 1);
    tryDir(step + 1);
    down(step + 1);
    tryDir(step + 1);
    left(step + 1);
    tryDir(step + 1);
    right(step + 1);
    tryDir(step + 1);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> boardSize;
    boardState.resize(6, std::vector<std::vector<int>>(boardSize, std::vector<int>(boardSize)));
    updated.resize(boardSize);
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            std::cin >> boardState[0][i][j];
            if (boardState[0][i][j] > maxVal) maxVal = boardState[0][i][j];
        }
    }
    if (boardSize > 1) tryDir(0);
    std::cout << maxVal << '\n';
}