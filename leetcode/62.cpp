class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> routes(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                routes[i][j] = routes[i-1][j] + routes[i][j-1];
            }
        }
        return routes[m-1][n-1];
    }
};