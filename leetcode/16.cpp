class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestToTarget = 100000000;
        sort(nums.begin(), nums.end());
        for (int i = 0, len = nums.size(); i < len - 2; ++i) {
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int calc = nums[i] + nums[left] + nums[right];
                if (abs(target - calc) < abs(target - closestToTarget)) closestToTarget = calc;
                if (calc < target) ++left;
                else --right;
            }
        }
        return closestToTarget;
    }
};