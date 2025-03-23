class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> connection(n);
        vector<bool> visited(n);
        int size = roads.size();
        for (int i = 0; i < size; ++i)
        {
            connection[roads[i][0]].push_back({ roads[i][1], roads[i][2] });
            connection[roads[i][1]].push_back({ roads[i][0], roads[i][2] });
        }
        std::stack<pair<int, int>> stk;
        int maxLen = numeric_limits<int>::max();
        stk.push({ 0, 0 });
        visited[0] = true;
        int cur = 0;
        int counts = 0;
        while (stk.empty() == false)
        {
            pair<int, int>& p = stk.top();
            size = connection[p.first].size();
            while (p.second < size)
            {
                if (visited[connection[p.first][p.second].first] == false && cur + connection[p.first][p.second].second <= maxLen)
                {
                    if (connection[p.first][p.second].first == n - 1)
                    {
                        if (maxLen == cur + connection[p.first][p.second].second)
                            counts = (counts + 1) % 1000000007;
                        else
                        {
                            counts = 1;
                            maxLen = cur + connection[p.first][p.second].second;
                        }
                    }
                    else
                        break;
                }
                ++p.second;
            }
            if (size == p.second)
            {
                visited[p.first] = false;
                stk.pop();
                if (stk.empty() == true)
                    break;
                cur -= connection[stk.top().first][stk.top().second - 1].second;
                continue;
            }
            stk.push({ connection[p.first][p.second].first, 0 });
            cur += connection[p.first][p.second].second;
            visited[p.first] = true;
            ++p.second;
        }
        return counts;
    }
};