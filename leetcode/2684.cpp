class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxMoves = 0;
        vector<vector<int>> moveCounts(row, vector<int>(col));
        queue<pair<int , int>> q;
        for (int i = 0; i < row; ++i) q.push({i, 0});
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i && grid[i][j] < grid[i - 1][j + 1] && 
            moveCounts[i][j] >= moveCounts[i - 1][j + 1]) {
                if (moveCounts[i - 1][j + 1] == 0 && j + 2 < col) q.push({i - 1, j + 1});
                moveCounts[i - 1][j + 1] = moveCounts[i][j] + 1;
                maxMoves = max(maxMoves, moveCounts[i - 1][j + 1]);
            }
            if (grid[i][j] < grid[i][j + 1] && moveCounts[i][j] >= moveCounts[i][j + 1]) {
                if (moveCounts[i][j + 1] == 0 && j + 2 < col) q.push({i, j + 1});
                moveCounts[i][j + 1] = moveCounts[i][j] + 1;
                maxMoves = max(maxMoves, moveCounts[i][j + 1]);
            }
            if (i + 1 < row && grid[i][j] < grid[i + 1][j + 1] && 
            moveCounts[i][j] >= moveCounts[i + 1][j + 1]) {
                if (moveCounts[i + 1][j + 1] == 0 && j + 2 < col) q.push({i + 1, j + 1});
                moveCounts[i + 1][j + 1] = moveCounts[i][j] + 1;
                maxMoves = max(maxMoves, moveCounts[i + 1][j + 1]);
            }       
        }
        return maxMoves;
    }
};