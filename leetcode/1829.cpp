class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans(nums.size());
        int bit = 0;
        int mask = (1 << maximumBit) - 1;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            bit ^= nums[i];
            ans[len - 1 - i] = (~bit) & mask;
        }
        return ans;
    }
};