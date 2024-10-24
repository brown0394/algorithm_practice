class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0, len = nums.size(), next = 1; i < len - 3; i = next++) {
            while (next < len && nums[i] == nums[next]) ++next;
            if (next > i + 3) i = next - 4;
            for (int j = i + 1; j < len - 2; ++j) {
                long long calc = nums[i] + nums[j];
                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    long long lr = nums[left] + nums[right];
                    if (calc + lr == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                    }
                    else if (calc + lr < target) ++left;
                    else --right;
                }
                while (j + 1 < len - 2 && nums[j] == nums[j + 1]) ++j;
            }
        }
        return ans;
    }
};