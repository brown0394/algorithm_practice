#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
struct coord {
    int r, c;
};
char floorMap[105][105];
std::bitset<26> keys;
int row, col;
std::vector<std::vector<coord>> lockedDoors(26);
std::vector<std::bitset<105>> visited(105);



int searchFloor(int i, int j) {
    int documentsFound = 0;
    std::queue<coord> q;
    visited[i][j] = true;
    q.push({ i, j });
    while (!q.empty()) {
        i = q.front().r;
        j = q.front().c;
        q.pop();
        if (floorMap[i][j] >= 'A' && floorMap[i][j] <= 'Z' && !keys[floorMap[i][j] - 'A']) {
            lockedDoors[floorMap[i][j] - 'A'].push_back({ i, j });
            continue;
        }
        if (floorMap[i][j] == '$') ++documentsFound;
        else if (floorMap[i][j] >= 'a' && floorMap[i][j] <= 'z') {
            int idx = floorMap[i][j] - 'a';
            keys[idx] = true;
            if (!lockedDoors[idx].empty()) {
                for (auto it = lockedDoors[idx].begin(), end = lockedDoors[idx].end(); it != end; ++it) {
                    q.push(std::move(*it));
                }
                lockedDoors[idx].clear();
            }
        }
        if (i + 1 < row && floorMap[i + 1][j] != '*' && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            q.push({ i + 1, j });
        }
        if (i && floorMap[i - 1][j] != '*' && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            q.push({ i - 1, j });
        }
        if (j + 1 < col && floorMap[i][j + 1] != '*' && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            q.push({ i, j + 1 });
        }
        if (j && floorMap[i][j - 1] != '*' && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            q.push({ i, j - 1 });
        }
    }

    return documentsFound;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; ++i) {
        keys = 0;
        std::cin >> row >> col;
        for (int j = 0; j < 26; ++j) lockedDoors[j].clear();
        for (int j = 0; j < row; ++j) {
            std::cin >> floorMap[j];
            visited[j] = 0;
        }
        char key;
        std::cin.get(key);
        while (true) {
            std::cin.get(key);
            if (key == '0' || key == '\n') break;
            keys[key - 'a'] = true;
        }
        int documentsFound = 0;
        for (int j = 0; j < col; ++j) {
            if (floorMap[0][j] != '*' && !visited[0][j]) {
                documentsFound += searchFloor(0, j);
            }
            if (floorMap[row-1][j] != '*' && !visited[row-1][j]) {
                documentsFound += searchFloor(row-1, j);
            }
        }
        for (int j = 0; j < row; ++j) {
            if (floorMap[j][0] != '*' && !visited[j][0]) {
                documentsFound += searchFloor(j, 0);
            }
            if (floorMap[j][col-1] != '*' && !visited[j][col-1]) {
                documentsFound += searchFloor(j, col-1);
            }
        }
        std::cout << documentsFound << '\n';
    }
}