class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                swap(matrix[i][l], matrix[i][r]);
                ++l; --r;
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (i) {
                int l1 = i, l2 = 0;
                int r1 = n-1, r2 = n-1-i;
                while (l1 < r1) {
                    swap(matrix[l1][l2], matrix[r1][r2]);
                    swap(matrix[l2][l1], matrix[r2][r1]);
                    ++l1; --r1;
                    ++l2; --r2;
                }
            }
            else {
                int l = 0, r = n-1;
                while (l < r) {
                    swap(matrix[l][l], matrix[r][r]);
                    ++l; --r;
                }
            }
        }
    }
};