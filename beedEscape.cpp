#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
struct coord {
    int r, c;
};
struct dir {
    int l, r, u, d;
};
int row, col;
char board[10][10];
std::vector<std::vector<dir>> directions;
coord goal;
std::vector<std::bitset<10>> visited;
bool found = false;

void checkRouteHoriziontal(int i, int j) {
    int startC = j;
    while (board[i][j] != '#') {
        directions[i][j].l = startC;
        ++j;
    }
    --j;
    int lastC = j;
    for (; j >= startC; --j) {
        directions[i][j].r = lastC;
    }
}

void checkRouteVertical(int i, int j) {
    int startR = i;
    while (board[i][j] != '#') {
        directions[i][j].u = startR;
        if (!directions[i][j].l) checkRouteHoriziontal(i, j);
        ++i;
    }
    --i;
    int lastR = i;
    for (; i >= startR; --i) {
        directions[i][j].d = lastR;
    }
}

void checkDirAndPoss(int row, int col, bool redfirst, bool sameLoc, bool sameDir, bool rowComp, int add) {
    if (sameLoc && sameDir) {
        if (redfirst) {
            visited[row][col] = true;
            if (rowComp) checkPossiblity({ row, col }, { row, col + add });
            checkPossiblity({ row, col }, { row, col + add });
        }
        else {
            visited[row][col + add] = true;
            checkPossiblity({ row, col + add }, { row, col });
        }
    }
    else {
        visited[red.r][directions[red.r][red.c].l] = true;
        checkPossiblity({ red.r, directions[red.r][red.c].l },
            { red.r, directions[red.r][red.c].l });
    }
}

void checkPossiblity(coord red, coord blue) {
    if (red.r == goal.r && red.c == goal.c) found = true;
    if (found) return;
    if (!visited[red.r][directions[red.r][red.c].l]) {
        if (blue.r == red.r && directions[red.r][red.c].l == directions[blue.r][blue.c].l) {
            if (red.c < blue.c) {
                visited[red.r][directions[red.r][red.c].l] = true;
                checkPossiblity({ red.r, directions[red.r][red.c].l },
                    { red.r, directions[red.r][red.c].l + 1 });
            }
            else {
                visited[red.r][directions[red.r][red.c].l + 1] = true;
                checkPossiblity({ red.r, directions[red.r][red.c].l + 1 },
                    { red.r, directions[red.r][red.c].l });
            }
        }
        else {
            visited[red.r][directions[red.r][red.c].l] = true;
            checkPossiblity({ red.r, directions[red.r][red.c].l },
                { red.r, directions[red.r][red.c].l });
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> row >> col;
    directions.resize(row, std::vector<dir>(col));
    visited.resize(row);
    for (int i = 0; i < row; ++i) {
        std::cin >> board[i];
    }
    coord redBall, blueBall;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (board[i][j] != '#' && !directions[i][j].u) {
                checkRouteVertical(i, j);
                switch (board[i][j]) {
                case 'R': { redBall.r = i; redBall.c = j; break; }
                case 'B': { blueBall.r = i; blueBall.c = j; break; }
                case 'O': { goal.r = i; goal.c = j; break; }
                }
            }
        }
    }
    int a = 10;
}