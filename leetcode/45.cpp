class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size() - 1;
        if (len == 0) return 0;
        int cur = 0, next = 0, nextPossible = nums[0];
        int jumps = 1;
        while (nextPossible < len) {
            for (int i = 1; i <= nums[cur]; ++i) {
                if (cur + i + nums[cur + i] > nextPossible) {
                    nextPossible = cur + i + nums[cur + i];
                    next = i;
                }
            }
            cur += next;
            next = 0;
            ++jumps; 
        }
        return jumps;
    }
};