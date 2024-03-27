#include <iostream>
#include <vector>

#define MAX 1000
struct node {
    int left;
    int up;
    int right;
};
std::vector<std::vector<node>>route;
std::vector<std::vector<int>>fuel;
int row, col;

void recordMinFuelUsage(int i, int j) {
    if (j) {
        if (route[i - 1][j - 1].up < route[i - 1][j - 1].right) {
            route[i][j].left = route[i - 1][j - 1].up + fuel[i][j];
        }
        else {
            route[i][j].left = route[i - 1][j - 1].right + fuel[i][j];
        }
    }
    else route[i][j].left = MAX;
    if (route[i - 1][j].left < route[i - 1][j].right) {
        route[i][j].up = route[i - 1][j].left + fuel[i][j];
    }
    else {
        route[i][j].up = route[i - 1][j].right + fuel[i][j];
    }
    if (j + 1 < col) {
        if (route[i - 1][j + 1].left < route[i - 1][j + 1].up) {
            route[i][j].right = route[i - 1][j + 1].left + fuel[i][j];
        }
        else {
            route[i][j].right = route[i - 1][j + 1].up + fuel[i][j];
        }
    }
    else route[i][j].right = MAX;
}

int main() {
    
    scanf_s("%d %d", &row, &col);
    route.resize(row, std::vector<node>(col));
    fuel.resize(row, std::vector<int>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf_s("%d", &fuel[i][j]);
        }
    }
    for (int j = 0; j < col; ++j) {
        route[0][j].left = fuel[0][j];
        route[0][j].up = route[0][j].left;
        route[0][j].right = route[0][j].left;
    }
    route[0][0].left = MAX;
    route[0][col - 1].left = MAX;
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            recordMinFuelUsage(i, j);
        }
    }
    --row;
    int min = MAX * MAX;
    for (int j = 0; j < col; ++j) {
        if (min > route[row][j].left) min = route[row][j].left;
        if (min > route[row][j].up) min = route[row][j].up;
        if (min > route[row][j].right) min = route[row][j].right;
    }
    printf("%d\n", min);
}