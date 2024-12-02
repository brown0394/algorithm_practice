class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, len = nums.size(), range = 0; i < len; ++i) {
            if (range < i) return false;
            range = max(range, i + nums[i]);
            if (range >= len-1) break;
        }
        return true;
    }
};