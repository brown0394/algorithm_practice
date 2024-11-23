class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (col == 1) return row;
        unordered_map<string, int> patternCount;

        for (int i = 0; i < row; ++i) {
            string pattern = "a";
            int match = matrix[i][0];
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == match) pattern.push_back('a');
                else pattern.push_back('b');
            }
            ++patternCount[pattern];
        }
        int ans = 0;
        for (pair<const string, int>& p : patternCount) {
            ans = max(ans, p.second);
        }
        return ans;
    }
};
