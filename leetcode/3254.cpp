class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int left = 0, right = k;
        int size = nums.size();
        bool lastWasValid = false;
        vector<int> ans;
        while (right <= size) {
            while (ans.size() < left) {
                ans.push_back(-1);
            }
            if (!lastWasValid) {
                lastWasValid = true;
                for (int i = left + 1; i < right; ++i) {
                    if (nums[i] - nums[i-1] != 1) {
                        left = i;
                        right = i + k;
                        lastWasValid = false;
                        break;
                    }
                }
                if (lastWasValid) {
                    ans.push_back(nums[right - 1]);
                    ++left; ++right;
                }
                continue;
            }
            if (nums[right - 1] - nums[right - 2] == 1) {
                ans.push_back(nums[right - 1]);
                ++left; ++right;
            }
            else {
                left = right - 1;
                right = left + k;
                lastWasValid = false;
            }
        }
        int till = size - k + 1;
        while (ans.size() < till) ans.push_back(-1);
        return ans;
    }
};