class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> falsePrefix(size);
        for (int i = 1; i < size; ++i) {
            falsePrefix[i] = falsePrefix[i-1];
            if (nums[i] % 2 == nums[i-1] % 2) ++falsePrefix[i];
        }
        size = queries.size();
        vector<bool> ans(size);
        for (int i = 0; i < size; ++i) {
            if (falsePrefix[queries[i][0]] == falsePrefix[queries[i][1]]) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};