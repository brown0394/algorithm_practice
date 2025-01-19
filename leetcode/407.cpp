
    struct boundary{
        int r, c, h;
        bool operator < (const boundary& other)
        {
            return h > other.h;
        }
    };
bool operator < (const boundary& one, const boundary& other)
{
    return one.h > other.h;
}
class Solution {

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size() - 1;
        int col = heightMap[0].size() - 1;
        vector<vector<bool>> visited(row+1, vector<bool>(col+1));
        priority_queue<boundary> pq;
        for (int i = 0; i <= row; ++i)
        {
            visited[i][0] = true;
            pq.push({i, 0, heightMap[i][0]});
            visited[i][col] = true;
            pq.push({i, col, heightMap[i][col]});
        }
        for (int j = 1; j < col; ++j)
        {
            visited[0][j] = true;
            pq.push({0, j, heightMap[0][j]});
            visited[row][j] = true;
            pq.push({row, j, heightMap[row][j]});
        }
        int ans = 0;
        while (pq.empty() == false)
        {
            auto [i, j, h] = pq.top();
            pq.pop();
            if (i > 0 && visited[i-1][j] == false)
            {
                visited[i-1][j] = true;
                if (heightMap[i-1][j] < heightMap[i][j])
                {
                    ans += (heightMap[i][j] - heightMap[i-1][j]);
                     heightMap[i-1][j] = heightMap[i][j];
                }
                pq.push({i-1, j, heightMap[i-1][j]});
            }
            if (i < row && visited[i+1][j] == false)
            {
                visited[i+1][j] = true;
                if (heightMap[i+1][j] < heightMap[i][j])
                {
                    ans += (heightMap[i][j] - heightMap[i+1][j]);
                    heightMap[i+1][j] = heightMap[i][j];
                }
                pq.push({i+1, j, heightMap[i+1][j]});
            }
            if (j > 0 && visited[i][j-1] == false)
            {
                visited[i][j-1] = true;
                if (heightMap[i][j-1] < heightMap[i][j])
                {
                    ans += (heightMap[i][j] - heightMap[i][j-1]);
                    heightMap[i][j-1] = heightMap[i][j];
                }
                pq.push({i, j-1, heightMap[i][j-1]});
            }
            if (j < col && visited[i][j+1] == false)
            {
                visited[i][j+1] = true;
                if (heightMap[i][j+1] < heightMap[i][j])
                {
                    ans += (heightMap[i][j] - heightMap[i][j+1]);
                    heightMap[i][j+1] = heightMap[i][j];
                }
                pq.push({i, j+1, heightMap[i][j+1]});
            }
        }
        return ans;
    }
};