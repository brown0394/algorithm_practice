class Solution {
    struct node
    {
        int i, j, dist;
    };
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> scoreGrid(row, vector<int>(col, 0));
        scoreGrid[0][0] = grid[0][0];
        for (int i = 1; i < row; ++i)
        {
            scoreGrid[i][0] = scoreGrid[i-1][0] + grid[i][0]; 
        }
        for (int j = 1; j < col; ++j)
        {
            scoreGrid[0][j] = scoreGrid[0][j-1] + grid[0][j]; 
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                scoreGrid[i][j] = min(scoreGrid[i-1][j] + grid[i][j], scoreGrid[i][j-1] + grid[i][j]);
            }
        }
        return scoreGrid[row-1][col-1];
    }
};