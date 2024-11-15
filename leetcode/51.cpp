class Solution {
    int nn;
    vector<vector<int>> placeable;
    vector<vector<string>> ans;
    vector<string> board;
    void markQ(int i, int j, int delta) {
        placeable[i][j] += delta;
        for (int plus = 1; i + plus < nn; ++plus) {
            placeable[i + plus][j] += delta;
            if (j - plus >= 0) placeable[i + plus][j - plus] += delta;
            if (j + plus < nn) placeable[i + plus][j + plus] += delta;
        }
    }
    void putQueen(int i, int j, int totQueens) {
        if (totQueens == nn) {
            ans.push_back(board);
        }
        for (; i < nn; ++i) {
            for (; j < nn; ++j) {
                if (0 == placeable[i][j]) {
                    board[i][j] = 'Q';
                    markQ(i, j, 1);
                    putQueen(i + 1, 0, totQueens + 1);
                    board[i][j] = '.';
                    markQ(i, j, -1);                   
                }
            }
            j = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        nn = n;
        placeable.resize(n, vector<int>(n));
        board.resize(n, string(n, '.'));
        putQueen(0, 0, 0);
        return ans;
    }
};