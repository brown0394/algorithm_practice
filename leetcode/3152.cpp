class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> falseIdx;
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] % 2 == nums[i+1] % 2) falseIdx.push_back(i);
        }
        size = queries.size();
        vector<bool> ans(size);
        for (int i = 0; i < size; ++i) {
            auto it = lower_bound(falseIdx.begin(), falseIdx.end(), queries[i][0]);
            if (it == falseIdx.end()) {
                ans[i] = true;
            }
            else if (*it + 1 <= queries[i][1]) ans[i] = false;
            else ans[i] = true;
        }
        return ans;
    }
};