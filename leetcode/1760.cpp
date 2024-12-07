class Solution {
    bool isValid(vector<int>& nums, int maxOperations, int target) {
        int operations = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] <= target) continue;
            operations += (nums[i] / target);
            if (nums[i] % target == 0) --operations;
            if (operations > maxOperations) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isValid(nums, maxOperations, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};