#include <iostream>
#include <vector>
#include <queue>

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    std::vector<std::vector<char>> map(row, std::vector<char>(col, 0));
    std::vector<std::vector<bool>> visit(row, std::vector<bool>(col, true));
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < row; ++i) {
        getchar();
        for (int j = 0; j < col; ++j) {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'I') {
                q.push(std::make_pair(i, j));
                visit[i][j] = false;
            }
            else if (map[i][j] == 'X') visit[i][j] = false;
        }
    }
    int i, j;
    int count = 0;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if (i + 1 < row && visit[i + 1][j]) {
            q.push(std::make_pair(i+1, j));
            visit[i+1][j] = false;
            if (map[i + 1][j] == 'P') ++ count;
        }
        if (i - 1 >= 0 && visit[i - 1][j]) {
            q.push(std::make_pair(i-1, j));
            visit[i-1][j] = false;
            if (map[i - 1][j] == 'P') ++ count;
        }
        if (j + 1 < col && visit[i][j + 1]) {
            q.push(std::make_pair(i, j+1));
            visit[i][j+1] = false;
            if (map[i][j + 1] == 'P') ++ count;
        }
        if (j - 1 >= 0 && visit[i][j - 1]) {
            q.push(std::make_pair(i, j-1));
            visit[i][j-1] = false;
            if (map[i][j - 1] == 'P') ++ count;
        }        
    }
    if (count) printf("%d\n", count);
    else printf("TT\n");
}