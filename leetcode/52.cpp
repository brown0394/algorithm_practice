class Solution {
    int nn, ans;
    vector<vector<int>> placeable;
    void markQ(int i, int j, int delta) {
        placeable[i][j] += delta;
        for (int plus = 1; i + plus < nn; ++plus) {
            placeable[i + plus][j] += delta;
            if (j - plus >= 0) placeable[i + plus][j - plus] += delta;
            if (j + plus < nn) placeable[i + plus][j + plus] += delta;
        }
    }
    void putQueen(int i, int totQueens) {
        if (totQueens == nn) {
            ++ans;
            return;
        }
        if (i == nn) return;
        for (int j = 0; j < nn; ++j) {
            if (0 == placeable[i][j]) {
                markQ(i, j, 1);
                putQueen(i + 1, totQueens + 1);
                markQ(i, j, -1);    
            }
        }
    }
public:
    int totalNQueens(int n) {
        nn = n;
        ans = 0;
        placeable.resize(n, vector<int>(n));
        putQueen(0, 0);
        return ans;
    }
};