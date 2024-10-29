class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxMoves = 0;
        vector<vector<int>> moveCounts(row, vector<int>(2, 1));
        int last = 0, cur = 1;
        for (int j = 1; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                moveCounts[i][cur] = 0;
                if (i && grid[i - 1][j - 1] < grid[i][j] && moveCounts[i-1][last]) {
                    moveCounts[i][cur] = max(moveCounts[i][cur], moveCounts[i-1][last] + 1);
                }
                if (grid[i][j - 1] < grid[i][j] && moveCounts[i][last]) {
                    moveCounts[i][cur] = max(moveCounts[i][cur], moveCounts[i][last] + 1);
                }
                if (i + 1 < row && grid[i + 1][j - 1] < grid[i][j] && moveCounts[i+1][last]) {
                    moveCounts[i][cur] = max(moveCounts[i][cur], moveCounts[i+1][last] + 1);
                }
                maxMoves = max(maxMoves, moveCounts[i][cur]);
            }
            swap(last, cur);
        }
        if (maxMoves) return maxMoves - 1;
        return maxMoves;
    }
};