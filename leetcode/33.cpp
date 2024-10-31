class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (nums[low] < nums[high]) low = high;
        else {
            while (low < high) {
                int mid = (low + high) >> 1;
                if (nums[mid] > nums[low]) low = mid;
                else high = mid;
            }
        }
        vector<int>::iterator found;
        if (target >= nums[0]) {
            found = lower_bound(nums.begin(), nums.begin() + low, target);
        }
        else {
            found = lower_bound(nums.begin() + low + 1, nums.end(), target);         
        }
        if (found == nums.end() || *found != target) return -1;
        return found - nums.begin();
    }
};