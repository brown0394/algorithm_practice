class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left = nums[0];
        long long right = 0;
        for (int i = 1, size = nums.size(); i < size; ++i) {
            right += nums[i];
        }
        int ans = 0;
        if (left >= right) ++ans;
        for (int i = 1, size = nums.size()-1; i < size; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) ++ans;
        }
        return ans;
    }
};