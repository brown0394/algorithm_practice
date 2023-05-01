#include <iostream>


class ChessPainter {
private:
    char board[50][51];
    char wFirst[9];
    char bFirst[9];
    int x, y, height, width;
    int calcPlaceToPaint(char* line);
public:
    ChessPainter(int h, int w): wFirst{"WBWBWBWB"}, bFirst{"BWBWBWBW"},
        height(h), width(w) {
        for (int i = 0; i < height; ++i) {
            scanf("%s", &board[i][0]);
        }
    }
    int getMin();
};

int ChessPainter::calcPlaceToPaint(char* line) {
    int yi;
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        yi = y + i;
        for (int j = 0; j < 8; ++j) {
            if (line[j] != board[yi][x+j]) {
                ++sum;
            }
        }
        if (line == wFirst) line = bFirst;
        else line = wFirst;
    }
    return sum;
}

int ChessPainter::getMin() {
    x = 0;
    y = 0;
    unsigned int min = 0 - 1;
    int sum;
    while (true) {
        if (width - x < 8) {
            x = 0;
            ++y;
            if (height - y < 8) {
                break;
            }
        }
        sum = calcPlaceToPaint(wFirst);
        if (sum < min) min = sum;
        sum = calcPlaceToPaint(bFirst);
        if (sum < min) min = sum;
        ++x;
    }
    return min;
}


int main() {
    int height, width;
    scanf("%d %d", &height, &width);
    ChessPainter painter(height, width);
    printf("%d\n", painter.getMin());
}