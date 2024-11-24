class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        long long sum = 0;
        int minVal = abs(matrix[0][0]);
        bool zeroExist = false;
        int negRs = 0;
        for (int i = 0; i < row; ++i) {
            int negCount = 0;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] < 0) {
                    ++negCount;
                    sum += -matrix[i][j];
                }
                else sum += matrix[i][j];
                minVal = min(minVal, abs(matrix[i][j]));
            }
            if (negCount % 2) {
                ++negRs;
            }
        }
        if (negRs % 2 == 0 || minVal == 0) {
            return sum;
        }
        return sum - (minVal << 1);
    }
};