
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j] == true)
                {
                    visited[i][j] = true;
                    continue;
                }
                visited[i][j] = true;
                int fishCaught = 0;
                q.push({i, j});
                while (q.empty() == false)
                {
                    auto [r, c] = q.front();
                    fishCaught += grid[r][c];
                    q.pop();
                    if (r > 0 && visited[r-1][c] == false && grid[r-1][c] > 0)
                    {
                        visited[r-1][c] = true;
                        q.push({r-1, c});
                    }
                    if (r+1 < row && visited[r+1][c] == false && grid[r+1][c] > 0)
                    {
                        visited[r+1][c] = true;
                        q.push({r+1, c});
                    }
                    if (c > 0 && visited[r][c-1] == false && grid[r][c-1] > 0)
                    {
                        visited[r][c-1] = true;
                        q.push({r, c-1});
                    }
                    if (c+1 < col && visited[r][c+1] == false && grid[r][c+1] > 0)
                    {
                        visited[r][c+1] = true;
                        q.push({r, c+1});
                    }
                }
                ans = max(ans, fishCaught);
            }
        }
        return ans;
    }
};