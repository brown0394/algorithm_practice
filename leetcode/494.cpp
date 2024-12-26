class Solution {
    int t;
    int ans;
    void check(vector<int>& nums, int idx, int sum) {
        if (idx == nums.size()) {
            if (sum == t) ++ans;
            return;
        }
        check(nums, idx + 1, sum + nums[idx]);
        check(nums, idx + 1, sum - nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        ans = 0;
        check(nums, 0, 0);
        return ans;
    }
};