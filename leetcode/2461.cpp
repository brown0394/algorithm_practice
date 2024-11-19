class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        int duplicate = 0;
        long long sum = 0, maxVal = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            auto found = check.find(nums[i]);
            if (found == check.end()) check.emplace(nums[i], 1);
            else {
                ++found->second;
                if (found->second == 2) ++duplicate;
            }
        }
        if (!duplicate) maxVal = max(maxVal, sum);
        for (int i = k, len = nums.size(); i < len; ++i) {
            if (nums[i-k] == nums[i]) continue;
            sum -= nums[i-k];
            auto found = check.find(nums[i-k]);
            if (found->second == 1) {
                check.erase(found);
            } 
            else {
                if (found->second == 2) --duplicate;
                --found->second;
            }
            sum += nums[i];
            found = check.find(nums[i]);
            if (found == check.end()) check.emplace(nums[i], 1);
            else {
                ++found->second;
                if (found->second == 2) ++duplicate;
            }
            if (!duplicate) maxVal = max(maxVal, sum);
        }
        return maxVal;
    }
};