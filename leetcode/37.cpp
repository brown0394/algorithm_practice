class Solution {
    vector<bitset<9>> vertical;
    vector<bitset<9>> horizontal;
    vector<bitset<9>> box;
    bool tryNum(vector<vector<char>>& board, int i, int j) {
        for (; i < 9; ++i) {
            while (j < 9) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        int idx = (j / 3) + ((i / 3) * 3);
                        if (vertical[j][k] || horizontal[i][k] || box[idx][k]) continue;
                        vertical[j][k] = true;
                        horizontal[i][k] = true;
                        box[idx][k] = true;
                        if (tryNum(board, i, j + 1)) {
                            board[i][j] = '1' + k;
                            return true;
                        }
                        vertical[j][k] = false;
                        horizontal[i][k] = false;
                        box[idx][k] = false;                        
                    }
                    return false;
                }
                ++j;
            }
            j = 0;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vertical.resize(9, false);
        horizontal.resize(9, false);
        box.resize(9, false);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int idx = (j / 3) + ((i / 3) * 3);
                vertical[j][board[i][j] - '1'] = true;
                horizontal[i][board[i][j] - '1'] = true;
                box[idx][board[i][j] - '1'] = true;
            }
        }
        tryNum(board, 0, 0);
    }
};