class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        
        int right = n-1, left = 0;
        int down = n-1, up = 1;
        int r = 0, c = 0;
        int cur = 1, target = n * n;
        while (cur < target)
        {
            for (; c < right; ++c)
                mat[r][c] = cur++;
            --right;
            for (; r < down; ++r)
                mat[r][c] = cur++;
            --down;
            for (; c > left; --c)
                mat[r][c] = cur++;
            ++left;
            for (; r > up; --r)
                mat[r][c] = cur++;
            ++up;            
        }
        mat[r][c] = cur;
        return mat;
    }
};