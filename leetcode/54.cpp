class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int num = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int amount = row*col;
        vector<int> ans(amount);
        int dir = 0;
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = 0, c = 0;
        const int INV = 222;
        while (num < amount) {
            ans[num++] = matrix[r][c];
            matrix[r][c] = INV;
            auto& [i, j] = directions[dir];
            if (r+i >= row || c + j >= col || r+i < 0 || c + j < 0 || 
            matrix[r+i][c+j] == INV) dir = (dir + 1) % 4;
            r += directions[dir].first;
            c += directions[dir].second;
        }
        return ans;
    }
};