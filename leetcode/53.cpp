class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur = nums[0];
        for (int i = 1, size = nums.size(); i < size; ++i) {
            if (cur < 0) {
                cur = nums[i];
            }
            else {
                cur += nums[i];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};