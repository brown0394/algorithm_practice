class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxV = 0;
        int size = nums.size();
        int left = 0, right = 0;
        while (right < size) {
            while (right < size && nums[left] + k >= nums[right] - k) ++right;
            maxV = max(maxV, right - left);
            ++left;
        }
        return maxV;
    }
};