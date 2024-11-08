class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> jumpsNeeded(len, len);
        jumpsNeeded[len - 1] = 0;
        for (int i = len - 2; i >= 0; --i) {
            jumpsNeeded[i] = len;
            for (int j = 1; i + j < len && j <= nums[i]; ++j) {
                jumpsNeeded[i] = min(jumpsNeeded[i], jumpsNeeded[i + j] + 1);
            }
        }
        return jumpsNeeded[0];
    }
};