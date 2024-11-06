class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int size = nums.size();
        int lastMax = -1;
        for (int i = 0; i < size; ++i) {
            int curMax = nums[i], curMin = nums[i];
            int bit = __builtin_popcount(nums[i]);
            for (int j = i + 1; j < size; ++j) {
                if (__builtin_popcount(nums[j]) != bit) break;
                curMax = max(curMax, nums[j]);
                curMin = min(curMin, nums[j]);
                i = j;
            }
            if (curMin < lastMax) return false;
            lastMax = curMax;
        }
        return true;
    }
};