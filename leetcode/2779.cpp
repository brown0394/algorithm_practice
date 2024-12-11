class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int count[300005]{0};
        int maxV = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            ++count[nums[i] + 100000];
            maxV = max(maxV, count[nums[i] + 100000]);
            for (int j = 1; j <= k; ++j) {
                ++count[nums[i] + 100000 + j];
                maxV = max(maxV, count[nums[i] + 100000 + j]);
                ++count[nums[i] + 100000 - j];
                maxV = max(maxV, count[nums[i] + 100000 - j]);
            }
        }
        return maxV;
    }
};