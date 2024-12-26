class Solution {
    int t;
    vector<unordered_map<int, int>> memo;
    int check(vector<int>& nums, int idx, int sum) {
        if (idx == nums.size()) {
            if (sum == t) return 1;
            return 0;
        }
        auto found = memo[idx].find(sum);
        if (found != memo[idx].end()) return found->second;
        int possibility = check(nums, idx + 1, sum + nums[idx]);
        possibility += check(nums, idx + 1, sum - nums[idx]);
        return memo[idx][sum] = possibility;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size());
        t = target;
        return check(nums, 0, 0);
    }
};