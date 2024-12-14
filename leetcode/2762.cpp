class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int size = nums.size();
        long long total = 0;
        int left = 0, right = 1;
        int minV = nums[0];
        int maxV = minV;
        bool minus = false;
        while (true) {
            while(right < size && abs(nums[right] - minV) <= 2 &&
             abs(nums[right] - maxV) <= 2) {
                minV = min(minV, nums[right]);
                maxV = max(maxV, nums[right]);
                ++right;
             }
            long long N = right - left;
            total += ((N * (N + 1)) >> 1);
            if (minus) --total;
            if (right == size) break;
            if (right - left == 1) {
                ++right;
                minus = false;
            }
            else minus = true;
            left = right - 1;
            minV = nums[left];
            maxV = nums[left];
        }
        return total;
    }
};