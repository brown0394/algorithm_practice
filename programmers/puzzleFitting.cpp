#include <queue>
#include <vector>

#define BLOCK 20
using namespace std;

struct node {
    int blocks;
    vector<vector<int>> shape;
};

void bfs(vector<vector<int>>& table, node& info, queue<pair<int, int>>& q, const int block) {
    int i, j, row = table.size(), col = table[0].size();
    int sRow = q.front().first, sCol = q.front().second;
    int sRowE = sRow + 1, sColE = sCol + 1;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if (i && table[i - 1][j] == block) {
            table[i - 1][j] = BLOCK;
            q.push({ i - 1, j });
            ++info.blocks;
            info.shape[i - 1 - sRow][j - sCol] = 1;
        }
        if (j && table[i][j - 1] == block) {
            table[i][j - 1] = BLOCK;
            q.push({ i, j - 1 });
            ++info.blocks;
            if (j - 1 < sCol) {
                for (auto it = info.shape.begin(); it != info.shape.end(); ++it) {
                    it->insert(it->begin(), 0);
                }
                --sCol;
            }
            info.shape[i - sRow][j - sCol - 1] = 1;
        }
        if (i + 1 < row && table[i + 1][j] == block) {
            table[i + 1][j] = BLOCK;
            q.push({ i + 1, j });
            ++info.blocks;
            if (i + 1 == sRowE) {
                info.shape.push_back(vector<int>(sColE - sCol, 0));
                ++sRowE;
            }
            info.shape[i - sRow + 1][j - sCol] = 1;
        }
        if (j + 1 < col && table[i][j + 1] == block) {
            table[i][j + 1] = BLOCK;
            q.push({ i, j + 1 });
            ++info.blocks;
            if (j + 1 == sColE) {
                for (auto it = info.shape.begin(); it != info.shape.end(); ++it) {
                    it->push_back(0);
                }
                ++sColE;
            }
            info.shape[i - sRow][j - sCol + 1] = 1;
        }
    }
}

void getBlockInfo(vector<vector<int>>& table, vector<node>& info, const int block) {
    for (int i = 0, len = table.size(); i < len; ++i) {
        for (int j = 0, col = table[i].size(); j < col; ++j) {
            if (table[i][j] == block) {
                table[i][j] = BLOCK;
                queue<pair<int, int>> q;
                q.push({ i, j });
                info.push_back(node{ 1, vector<vector<int>>(1, vector<int>(1, 1))});
                bfs(table, info.back(), q, block);
            }
        }
    }
}

void rotate90Right(node& info) {
    int len = info.shape.size()-1;
    vector<vector<int>> origin(info.shape);
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len; ++j) {
            info.shape[i][j] = origin[len - j][i];
        }
    }
}

void rotate90Rect(node& info) {
    int row = info.shape.size() - 1;
    int col = info.shape[0].size() - 1;
    vector<vector<int>> origin(info.shape);
    if (row > col) {
        for (int i = 0; i <= col; ++i) {
            info.shape[i].resize(row + 1);
        }
        for (int i = 0; i <= col; ++i) {
            for (int j = 0; j <= row; ++j) {
                info.shape[i][j] = origin[row - j][i];
            }
        }
        info.shape.resize(col + 1);
    }
    else {
        info.shape.resize(col + 1);
        for (int i = row + 1; i <= col; ++i) {
            info.shape[i].resize(row + 1);
        }
        for (int i = 0; i <= row; ++i) {
            for (int j = 0; j <= col; ++j) {
                info.shape[j][i] = origin[row - i][j];
            }
        }
        for (int i = 0; i <= row; ++i) {
            info.shape[i].resize(row + 1);
        }
    }
}

void rotate180(node& info) {
    int row = info.shape.size() - 1;
    int col = info.shape[0].size() - 1;
    vector<vector<int>> origin(info.shape);
    for (int i = 0; i <= row; ++i) {
        for (int j = 0; j <= col; ++j) {
            info.shape[i][j] = origin[row - i][col - j];
        }
    }
}

bool fitting(vector<node>& gbInfos, vector<node>& tbInfos, int gidx, int tidx) {
    int gRow = gbInfos[gidx].shape.size()-1;
    int gCol = gbInfos[gidx].shape[0].size()-1;
    int tRow = tbInfos[tidx].shape.size()-1;
    int tCol = tbInfos[tidx].shape[0].size()-1;
    bool found;
    if (gRow == tRow && gCol == tCol) {
        for (int k = 0; k < 4; ++k) {
            found = true;
            for (int i = 0; i <= gRow; ++i) {
                for (int j = 0; j <= gCol; ++j) {
                    if (gbInfos[gidx].shape[i][j] != tbInfos[tidx].shape[i][j]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) return true;
            rotate90Right(tbInfos[tidx]);
        }

    }
    else if (gCol == tRow && gRow == tCol) {
        rotate90Rect(tbInfos[tidx]);
        for (int k = 0; k < 2; ++k) {
            found = true;
            for (int i = 0; i <= gRow; ++i) {
                for (int j = 0; j <= gCol; ++j) {
                    if (gbInfos[gidx].shape[i][j] != tbInfos[tidx].shape[i][j]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) return true;
            rotate180(tbInfos[tidx]);
        }
    }
    return false;
}

int blocksFit(vector<node>& gbInfos, vector<node>& tbInfos) {
    int sum = 0;
    int tlen = tbInfos.size(), glen = gbInfos.size();
    for (int i = 0; i < glen; ++i) {
        for (int j = 0; j < tlen; ++j) {
            if (gbInfos[i].blocks == tbInfos[j].blocks && fitting(gbInfos, tbInfos, i, j)) {
                sum += gbInfos[i].blocks;
                tbInfos[j].blocks = 0;
                break;
            }
        }
    }
    return sum;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<node> gbInfos;
    getBlockInfo(game_board, gbInfos, 0);
    vector<node> tbInfos;
    getBlockInfo(table, tbInfos, 1);
    return blocksFit(gbInfos, tbInfos);
}

int main() {
    vector<vector<int>> game_board{ {1, 0, 1}, {0,0,0}, {0, 1, 1} };
    vector<vector<int>> table{ {1, 1, 0}, {1, 1, 0}, {0, 1, 0} };
    solution(game_board, table);
}