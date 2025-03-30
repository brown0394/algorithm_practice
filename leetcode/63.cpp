class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> routes(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            routes[i][0] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            routes[0][i] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    routes[i][j] = 0;
                    continue;
                }
                routes[i][j] = routes[i-1][j] + routes[i][j-1];
            }
        }
        return routes[m-1][n-1];
    }
};