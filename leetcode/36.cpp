class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> vertical(9);
        vector<bitset<9>> horizontal(9);
        vector<bitset<9>> box(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (vertical[j][board[i][j] - '1']) return false;
                vertical[j][board[i][j] - '1'] = true;
                if (horizontal[i][board[i][j] - '1']) return false;
                horizontal[i][board[i][j] - '1'] = true;
                int idx = (j / 3) + ((i / 3) * 3);
                if (box[idx][board[i][j] - '1']) return false;
                box[idx][board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};