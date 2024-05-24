#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#define BLOCK 5

using namespace std;

struct blockInfo {
    unsigned char shape[6];
    int blocks, row, col;
};

blockInfo bfs(int i, int j, vector<vector<int>>& table, const int block) {
    queue<pair<int, int>> q;
    blockInfo info{ {0}, 0, 0, 0 };
    q.push({ i, j });
    int row = table.size();
    int col = table[0].size();
    int srow = i, scol = j;
    table[i][j] = BLOCK;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        ++info.blocks;
        info.shape[i - srow] |= 1 << (7 - (j-scol));
        if (i + 1 < row && table[i + 1][j] == block) {
            if (i - srow == info.row) ++info.row;
            table[i + 1][j] = BLOCK;
            q.push({ i + 1, j });
        }
        if (i && table[i - 1][j] == block) {
            table[i - 1][j] = BLOCK;
            if (i == srow) {
                --srow;
                ++info.row;
                for (int k = 5; k >= 1; --k) info.shape[k] = info.shape[k - 1];
                info.shape[0] = 0;
            }
            q.push({ i - 1, j });
        }
        if (j + 1 < col && table[i][j + 1] == block) {
            if (j - scol == info.col) ++info.col;
            table[i][j + 1] = BLOCK;
            q.push({ i, j + 1 });
        }
        if (j && table[i][j - 1] == block) {
            table[i][j - 1] = BLOCK;
            if (j == scol) {
                --scol;
                ++info.col;
                for (int k = 0; k < 6; ++k) info.shape[k] >>= 1;
            }
            q.push({ i, j - 1 });
        }
    }
    return info;
}

bool compareBlock(blockInfo& one, blockInfo& two) {
    for (int i = 0; i <= one.row; ++i) {
        if (one.shape[i] != two.shape[i]) return false;
    }
    return true;
}

void rotate90(blockInfo& block) {
    unsigned char temp[6]{ 0 };
    int tempCur = 1 << 7;
    for (int i = block.row; i >= 0; --i) {
        int cur = 1 << 7;
        for (int j = 0; j <= block.col; ++j) {
            if (cur & block.shape[i]) {
                temp[j] |= tempCur;
            }
            cur >>= 1;
        }
        tempCur >>= 1;
    }
    int rc = block.row;
    block.row = block.col;
    block.col = rc;
    for (int i = 0; i <= block.row; ++i) {
        block.shape[i] = temp[i];
    }
}

void rotate180(blockInfo& block) {
    unsigned char temp[6]{ 0 };
    int idx = 0;
    for (int i = block.row; i >= 0; --i) {
        int cur = 1 << 7 - block.col;
        int tempCur = 1 << 7;
        for (int j = 0; j <= block.col; ++j) {
            if (cur & block.shape[i]) {
                temp[idx] |= tempCur;
            }
            cur <<= 1;
            tempCur >>= 1;
        }
        ++idx;
    }
    for (int i = 0; i <= block.row; ++i) {
        block.shape[i] = temp[i];
    }
}

bool compareBlocks(blockInfo& one, blockInfo& two) {
    bool result = false;
    if (one.row == two.row && one.col == two.col) {
        result = compareBlock(one, two);
        if (result) return true;
        if (one.row == one.col) {
            for (int i = 0; i < 3; ++i) {
                rotate90(two);
                result = compareBlock(one, two);
                if (result) return true;
            }
        }
        else {
            rotate180(two);
            result = compareBlock(one, two);
        }
    }
    else if (one.row == two.col && one.col == two.row) {
        rotate90(two);
        result = compareBlock(one, two);
        if (result) return true;
        rotate180(two);
        result = compareBlock(one, two);
    }
    return result;
}

void printBlock(blockInfo& block) {
    for (int k = 0; k <= block.row; ++k) {
        int check = 1 << 7;
        for (int l = 0; l <= block.col; ++l) {
            if (block.shape[k] & check) printf("1");
            else printf("0");
            check >>= 1;
        }
        printf("\n");
    }
    printf("\n");
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<list<blockInfo>> blocks(7);
    blockInfo block;
    for (int i = 0, row = table.size(); i < row; ++i) {
        for (int j = 0, col = table[i].size(); j < col; ++j) {
            if (table[i][j] == 1) {
                block = bfs(i, j, table, 1);
                blocks[block.blocks].emplace_back(move(block));
            }
        }
    }
    
    for (int i = 0, row = game_board.size(); i < row; ++i) {
        for (int j = 0, col = game_board[i].size(); j < col; ++j) {
            if (!game_board[i][j]) {
                block = bfs(i, j, game_board, 0);
                for (auto it = blocks[block.blocks].begin(); it != blocks[block.blocks].end(); ++it) {
                    if (compareBlocks(block, *it)) {
                        answer += block.blocks;
                        blocks[block.blocks].erase(it);
                        break;
                    }
                }
            }
        }
    }
    return answer;
}