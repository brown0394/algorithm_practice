#include <string>
#include <queue>
#include <vector>
#include <algorithm>

#define CHECKED 10
#define BLOCK 20
using namespace std;

struct node {
    int blocks;
    int startI;
    int startJ;
    int endI;
    int endJ;
    bool operator < (const node& other) {
        return blocks < other.blocks;
    }
};

void bfs(vector<vector<int>>& table, node& info, int block) {
    queue<pair<int, int>> q;
    q.push({ info.startI, info.startJ });
    int i, j, len = table.size();
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if (i && table[i - 1][j] == block) {
            table[i - 1][j] = BLOCK;
            q.push({ i - 1, j });
            ++info.blocks;
            if (i - 1 < info.startI) info.startI = i - 1;
        }
        if (j && table[i][j - 1] == block) {
            table[i][j - 1] = BLOCK;
            q.push({ i, j - 1 });
            ++info.blocks;
            if (j - 1 < info.startJ) info.startJ = j - 1;
        }
        if (i + 1 < len && table[i + 1][j] == block) {
            table[i + 1][j] = BLOCK;
            q.push({ i + 1, j });
            ++info.blocks;
            if (i + 1 > info.endI) info.endI = i + 1;
        }
        if (j + 1 < len && table[i][j + 1] == block) {
            table[i][j + 1] = BLOCK;
            q.push({ i, j + 1 });
            ++info.blocks;
            if (j + 1 > info.endJ) info.endJ = j + 1;
        }
    }
}

void getBlockInfo(vector<vector<int>>& table, vector<node>& info, int block) {
    for (int i = 0, len = table.size(); i < len; ++i) {
        for (int j = 0, col = table[i].size(); j < col; ++j) {
            if (table[i][j] == block) {
                table[i][j] = BLOCK;
                info.push_back(node{ 1, i, j, i, j });
                bfs(table, info.back(), block);
            }
            else if (table[i][j] != BLOCK) {
                table[i][j] = CHECKED;
            }
        }
    }
}

bool fitting(vector<vector<int>>& game_board, vector<vector<int>>& table,
    vector<node>& gbInfos, vector<node>& tbInfos, int gidx, int tidx) {
    int gRow = gbInfos[gidx].endI - gbInfos[gidx].startI;
    int gCol = gbInfos[gidx].endJ - gbInfos[gidx].startJ;
    int tRow = tbInfos[tidx].endI - tbInfos[tidx].startI;
    int tCol = tbInfos[tidx].endJ - tbInfos[tidx].startJ;
    bool found;
    if (gRow == tRow && gCol == tCol) {
        found = true;
        for (int i = 0; i <= gRow; ++i) {
            for (int j = 0; j <= gCol; ++j) {
                if (game_board[gbInfos[gidx].startI + i][gbInfos[gidx].startJ + j] != table[tbInfos[tidx].startI + i][tbInfos[tidx].startJ + j]) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return true;
        found = true;
        for (int i = 0; i <= gRow; ++i) {
            for (int j = 0; j <= gCol; ++j) {
                if (game_board[gbInfos[gidx].startI + i][gbInfos[gidx].startJ + j] != table[tbInfos[tidx].endI - i][tbInfos[tidx].endJ - j]) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return true;
    }
    if (gCol == tRow && gRow == tCol) {
        found = true;
        for (int i = 0; i <= gRow; ++i) {
            for (int j = 0; j <= gCol; ++j) {
                if (game_board[gbInfos[gidx].startI + i][gbInfos[gidx].startJ + j] != table[tbInfos[tidx].endI - j][tbInfos[tidx].startJ + i]) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return true;
        found = true;
        for (int i = 0; i <= gRow; ++i) {
            for (int j = 0; j <= gCol; ++j) {
                if (game_board[gbInfos[gidx].startI + i][gbInfos[gidx].startJ + j] != table[tbInfos[tidx].startI + j][tbInfos[tidx].endJ - i]) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return true;
    }


    return 0;
}

int blocksFit(vector<vector<int>>& game_board, vector<vector<int>>& table,
    vector<node>& gbInfos, vector<node>& tbInfos) {
    int tidx = 0, gidx = 0, sum = 0;
    int tlen = tbInfos.size(), glen = gbInfos.size();
    int lastG = 0, lastT = 0;
    while (tidx < tlen && gidx < glen) {
        if (gbInfos[gidx].blocks == tbInfos[tidx].blocks) {
            if (tbInfos[tidx].blocks != tbInfos[lastT].blocks) lastT = tidx;
            if (fitting(game_board, table, gbInfos, tbInfos, gidx, tidx)) {
                lastG = gbInfos[gidx].blocks;
                sum += gbInfos[gidx++].blocks;
                tbInfos[tidx].blocks = 0;
                if (gidx < glen && gbInfos[gidx].blocks == lastG) tidx = lastT - 1;
            }
            ++tidx;
        }
        else if (gbInfos[gidx].blocks < tbInfos[tidx].blocks) {
            lastG = gbInfos[gidx].blocks;
            ++gidx;
        }
        else ++tidx;
    }
    return sum;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    vector<node> gbInfos;
    getBlockInfo(game_board, gbInfos, 0);
    vector<node> tbInfos;
    getBlockInfo(table, tbInfos, 1);
    sort(gbInfos.begin(), gbInfos.end());
    sort(tbInfos.begin(), tbInfos.end());
    return blocksFit(game_board, table, gbInfos, tbInfos);
}

int main() {
    vector<vector<int>> game_board{ {1, 1, 0}, {0, 0, 0}, {0, 1, 1} };
    vector<vector<int>> table{ {1, 1, 0}, {0, 1, 0}, {0, 1, 1} };
    solution(game_board, table);
}