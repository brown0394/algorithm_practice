#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
struct coord {
    int r, c;
};
struct dir {
    int l, r, u, d;
};//segfault, bluevisit

struct node {
    coord red, blue;
    int step;
};
int row, col;
char board[11][11];
std::vector<std::vector<dir>> directions;
coord goal;
std::vector<std::vector<std::vector<std::bitset<15>>>> visited;
int found = 0;

void checkRouteHoriziontal(int i, int j) {
    int startC = j;
    if (board[i][j] == 'O') {
        ++j;
    }
    while (board[i][j] != '#') {
        directions[i][j].l = startC;
        ++j;
        if (board[i][j - 1] == 'O') break;
    }
    --j;
    int lastC = j;
    for (; j >= startC; --j) {
        directions[i][j].r = lastC;
    }
}

void checkRouteVertical(int i, int j) {
    int startR = i;
    if (board[i][j] == 'O') {
        checkRouteHoriziontal(i, j);
        ++i;
    }
    while (board[i][j] != '#') {
        directions[i][j].u = startR;
        if (!directions[i][j].l) checkRouteHoriziontal(i, j);
        ++i;
        if (board[i - 1][j] == 'O') {
            directions[i - 1][j].u = 0;
            break;
        }
    }
    --i;
    int lastR = i;
    for (; i >= startR; --i) {
        directions[i][j].d = lastR;
    }
}

void checkDirAndPoss(int row, int col, bool redfirst, bool rowComp, int add,
    std::queue<node>& q, int step) {
    if (redfirst) {
        if (rowComp) {
            if (visited[row][col][row + add][col]) return;
            if (board[row][col] == 'O' || board[row + add][col] == 'O') step = -1;
            else visited[row][col][row + add][col] = true;
            q.push({ { row, col }, { row + add, col }, step });
        }
        else {
            if (visited[row][col][row][col + add]) return;
            if (board[row][col] == 'O' || board[row][col + add] == 'O') step = -1;
            else visited[row][col][row][col + add] = true;
            q.push({ { row, col }, { row, col + add }, step });
        }
    }
    else {
        if (rowComp) {
            if (visited[row + add][col][row][col]) return;
            if (board[row + add][col] == 'O' || board[row][col] == 'O') step = -1;
            else visited[row + add][col][row][col] = true;
            q.push({ { row + add, col }, { row, col }, step });
        }
        else {
            if (visited[row][col + add][row][col]) return;
            if (board[row][col + add] == 'O' || board[row][col] == 'O') step = -1;
            else visited[row][col + add][row][col] = true;
            q.push({ { row, col + add }, { row, col }, step });
        }
    }
}

int checkPossiblity(coord& red, coord& blue) {
    std::queue<node> q;
    q.push({ red, blue, 0 });
    node cur;
    while (!q.empty()) {
        cur = std::move(q.front());
        q.pop();
        if (cur.step > 10) return -1;
        if (cur.step < 0 || (cur.blue.r == goal.r && cur.blue.c == goal.c)) continue;
        if (cur.red.r == goal.r && cur.red.c == goal.c) return cur.step;

        if (cur.red.r == cur.blue.r && directions[cur.red.r][cur.red.c].l == directions[cur.blue.r][cur.blue.c].l) {
            checkDirAndPoss(cur.red.r, directions[cur.red.r][cur.red.c].l,
                (cur.red.c < cur.blue.c), false, 1, q, cur.step + 1);
        }
        else if (!visited[cur.red.r][directions[cur.red.r][cur.red.c].l][cur.blue.r][directions[cur.blue.r][cur.blue.c].l]) {
            visited[cur.red.r][directions[cur.red.r][cur.red.c].l][cur.blue.r][directions[cur.blue.r][cur.blue.c].l] = true;
            q.push({ {cur.red.r, directions[cur.red.r][cur.red.c].l}, {cur.blue.r, directions[cur.blue.r][cur.blue.c].l}, cur.step + 1 });
        }
        if (cur.red.r == cur.blue.r && directions[cur.red.r][cur.red.c].r == directions[cur.blue.r][cur.blue.c].r) {
            checkDirAndPoss(cur.red.r, directions[cur.red.r][cur.red.c].r, (cur.red.c > cur.blue.c), false, -1, q, cur.step + 1);
        }
        else if (!visited[cur.red.r][directions[cur.red.r][cur.red.c].r][cur.blue.r][directions[cur.blue.r][cur.blue.c].r]) {
            visited[cur.red.r][directions[cur.red.r][cur.red.c].r][cur.blue.r][directions[cur.blue.r][cur.blue.c].r] = true;
            q.push({ {cur.red.r, directions[cur.red.r][cur.red.c].r}, {cur.blue.r, directions[cur.blue.r][cur.blue.c].r}, cur.step + 1 });
        }
        if (cur.red.c == cur.blue.c && directions[cur.red.r][cur.red.c].u == directions[cur.blue.r][cur.blue.c].u) {
            checkDirAndPoss(directions[cur.red.r][cur.red.c].u, cur.red.c, (cur.red.r < cur.blue.r), true, 1, q, cur.step + 1);
        }
        else if (!visited[directions[cur.red.r][cur.red.c].u][cur.red.c][directions[cur.blue.r][cur.blue.c].u][cur.blue.c]) {
            visited[directions[cur.red.r][cur.red.c].u][cur.red.c][directions[cur.blue.r][cur.blue.c].u][cur.blue.c] = true;
            q.push({ {directions[cur.red.r][cur.red.c].u, cur.red.c}, {directions[cur.blue.r][cur.blue.c].u, cur.blue.c}, cur.step + 1 });
        }
        if (cur.red.c == cur.blue.c && directions[cur.red.r][cur.red.c].d == directions[cur.blue.r][cur.blue.c].d) {
            checkDirAndPoss(directions[cur.red.r][cur.red.c].d, cur.red.c, (cur.red.r > cur.blue.r), true, -1, q, cur.step + 1);
        }
        else if (!visited[directions[cur.red.r][cur.red.c].d][cur.red.c][directions[cur.blue.r][cur.blue.c].d][cur.blue.c]) {
            visited[directions[cur.red.r][cur.red.c].d][cur.red.c][directions[cur.blue.r][cur.blue.c].d][cur.blue.c] = true;
            q.push({ {directions[cur.red.r][cur.red.c].d, cur.red.c}, {directions[cur.blue.r][cur.blue.c].d, cur.blue.c}, cur.step + 1 });
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> row >> col;
    directions.resize(row + 1, std::vector<dir>(col + 1));
    visited.resize(row + 1, std::vector<std::vector<std::bitset<15>>>(col + 1, std::vector<std::bitset<15>>(row + 1)));
    for (int i = 0; i < row; ++i) {
        std::cin >> board[i];
    }
    coord redBall, blueBall;
    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            if (board[i][j] != '#' && !directions[i][j].u) {
                checkRouteVertical(i, j);
            }
            switch (board[i][j]) {
            case 'R': { redBall.r = i; redBall.c = j; break; }
            case 'B': { blueBall.r = i; blueBall.c = j; break; }
            case 'O': { goal.r = i; goal.c = j; break; }
            }
        }
    }
    visited[redBall.r][redBall.c][blueBall.r][blueBall.c] = true;
    std::cout << checkPossiblity(redBall, blueBall) << '\n';
}