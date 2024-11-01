class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        bool one = false;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) one = true; 
            if (nums[i] <= 0 || nums[i] > len) nums[i] = 1;
        }
        if (!one) return 1;
        for (int i = 0; i < len; ++i) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return len + 1;
    }
};