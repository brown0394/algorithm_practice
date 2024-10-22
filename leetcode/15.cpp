class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0, len = nums.size(); i < len-2; ++i) {
            if (i) {
                while (i < len - 2 && nums[i] == nums[i - 1]) ++i;
            }
            if (nums[i] > 0) break;
            for (int j = i + 1; j < len - 1; ++j) {
                if (nums[i] + nums[j] > 0) break;
                int third = 0 - (nums[i] + nums[j]);
                if (answer.empty() || nums[i] != answer.back()[0] ||
                nums[j] != answer.back()[1] || third != answer.back()[2]) {
                    auto found = lower_bound(nums.begin() + j + 1, nums.end(), third);
                    if (found != nums.end() && *found == third) {
                        answer.push_back({nums[i], nums[j], third});
                    }
                }
            }
        }
        return answer;
    }
};