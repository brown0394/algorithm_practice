class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        vector<vector<pair<int,int>>> countGrid(row, vector<pair<int, int>>(col));
        int id = 1;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] > 0 && visited[i][j] == false)
                {
                    queue<pair<int, int>> q;
                    stack<pair<int, int>> stk;
                    visited[i][j] = true;
                    q.push({i, j});
                    while (q.empty() == false)
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        stk.push({r, c});
                        if (r + 1 < row && visited[r+1][c] == false && grid[r+1][c] > 0)
                        {
                            visited[r+1][c] = true;
                            q.push({r+1, c});
                        }
                        if (r > 0 && visited[r-1][c] == false && grid[r-1][c] > 0)
                        {
                            visited[r-1][c] = true;
                            q.push({r-1, c});
                        }
                        if (c + 1 < col && visited[r][c+1] == false && grid[r][c+1] > 0)
                        {
                            visited[r][c+1] = true;
                            q.push({r, c+1});
                        }
                        if (c > 0 && visited[r][c-1] == false && grid[r][c-1] > 0)
                        {
                            visited[r][c-1] = true;
                            q.push({r, c-1});
                        }
                    }
                    int size = stk.size();
                    while (stk.empty() == false)
                    {
                        auto [r, c] = stk.top();
                        stk.pop();
                        countGrid[r][c].first = size;
                        countGrid[r][c].second = id;
                    }
                    ++id;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (countGrid[i][j].first > 0)
                    continue;
                int sum = 1;
                pair<int, int> l, r, u, d;
                if (j > 0) l = countGrid[i][j-1];
                if (j+1 < col) r = countGrid[i][j+1];
                if (i > 0) u = countGrid[i-1][j];
                if (i+1 < row) d = countGrid[i+1][j];
                unordered_set<int> check;
                check.insert(l.second);
                sum += l.first;
                if (check.find(r.second) == check.end())
                {
                    sum += r.first;
                    check.insert(r.second);
                }
                if (check.find(u.second) == check.end())
                {
                    sum += u.first;
                    check.insert(u.second);
                }
                if (check.find(d.second) == check.end())
                {
                    sum += d.first;
                    check.insert(d.second);
                }
                ans = max(ans, sum);
            }
        }
        if (ans == 0) return countGrid[0][0].first;
        return ans;
    }
};