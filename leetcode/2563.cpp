class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        long long pairs = 0;
        while (left < right) {
            if (mid > right) mid = right;
            else if (mid < left) mid = left;
            if (nums[left] + nums[right] <= upper) {
                while (mid < right && nums[mid] + nums[left] < lower) ++mid;
                while (mid > left && nums[mid-1] + nums[left] >= lower) --mid;
                if (mid == right) {
                    if (nums[left] + nums[right] >= lower) ++pairs;
                }
                else {
                    pairs += right - mid;
                    if (mid > left) ++pairs;
                }
                ++left;
            }
            else --right;
        }
        return pairs;
    }
};