class Solution {

public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, row*col + 1));
        visited[row-1][col-1] = 0;
        queue<pair<int, int>> q;
        q.push({row-1, col-1});
        while (q.empty() == false)
        {
            auto[i, j] = q.front();
            q.pop();

            if (i > 0)
            {
                if (grid[i-1][j] == 3 && visited[i-1][j] > visited[i][j])
                {
                    visited[i-1][j] = visited[i][j];
                    q.push({i-1, j});
                }
                else if (visited[i-1][j] > visited[i][j] + 1)
                {
                    visited[i-1][j] = visited[i][j] + 1;
                    q.push({i-1, j});
                }
            }
            if (i + 1 < row)
            {
                if (grid[i+1][j] == 4 && visited[i+1][j] > visited[i][j])
                {
                    visited[i+1][j] = visited[i][j];
                    q.push({i+1, j});
                }
                else if (visited[i+1][j] > visited[i][j] + 1)
                {
                    visited[i+1][j] = visited[i][j] + 1;
                    q.push({i+1, j});
                }
            }
            if (j > 0)
            {
                if (grid[i][j-1] == 1 && visited[i][j-1] > visited[i][j])
                {
                    visited[i][j-1] = visited[i][j];
                    q.push({i, j-1});
                }
                else if (visited[i][j-1] > visited[i][j] + 1)
                {
                    visited[i][j-1] = visited[i][j] + 1;
                    q.push({i, j-1});
                }
            }
            if (j + 1 < col)
            {
                if (grid[i][j+1] == 2 && visited[i][j+1] > visited[i][j])
                {
                    visited[i][j+1] = visited[i][j];
                    q.push({i, j+1});
                }
                else if (visited[i][j+1] > visited[i][j] + 1)
                {
                    visited[i][j+1] = visited[i][j] + 1;
                    q.push({i, j+1});
                }
            }
        }
        return visited[0][0];
    }
};