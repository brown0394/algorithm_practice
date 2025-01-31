class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        unordered_map<int, int> idMap;
        int id = 2;
        idMap[0] = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int count = 0;
                    grid[i][j] = id;
                    while (q.empty() == false)
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        ++count;
                        if (r + 1 < row && grid[r+1][c] == 1)
                        {
                            grid[r+1][c] = id;
                            q.push({r+1, c});
                        }
                        if (r > 0 && grid[r-1][c] == 1)
                        {
                            q.push({r-1, c});
                            grid[r-1][c] = id;
                        }
                        if (c + 1 < col && grid[r][c+1] == 1)
                        {
                            q.push({r, c+1});
                            grid[r][c+1] = id;
                        }
                        if (c > 0 && grid[r][c-1] == 1)
                        {
                            q.push({r, c-1});
                            grid[r][c-1] = id;
                        }
                    }
                    idMap[id++] = count;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] > 0)
                    continue;
                int sum = 1;
                unordered_set<int> check;
                if (j > 0) 
                {
                    check.insert(grid[i][j-1]);
                    sum += idMap[grid[i][j-1]];
                }
                if (j+1 < col && check.find(grid[i][j+1]) == check.end())
                {
                    sum += idMap[grid[i][j+1]];
                    check.insert(grid[i][j+1]);
                }
                if (i > 0 && check.find(grid[i-1][j]) == check.end())
                {
                    sum += idMap[grid[i-1][j]];
                    check.insert(grid[i-1][j]);
                }
                if (i+1 < row && check.find(grid[i+1][j]) == check.end())
                {
                    sum += idMap[grid[i+1][j]];
                    check.insert(grid[i+1][j]);
                }
                ans = max(ans, sum);
            }
        }
        if (ans == 0) return idMap[grid[0][0]];
        return ans;
    }
};