class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0, len = nums.size(); i < len-2; ++i) {
            if (i) {
                while (i < len - 2 && nums[i] == nums[i - 1]) ++i;
            }
            int left = i + 1;
            if (nums[i] + nums[left] > 0) break;
            int right = len - 1;
            while (left < right) {
                int calc = nums[i] + nums[left] + nums[right];
                if (calc == 0) {
                    answer.push_back({nums[i], nums[left++], nums[right]});
                    while(left < right && nums[left - 1] == nums[left]) ++left;
                }
                else if (calc < 0) ++left;
                else --right;
            }
        }
        return answer;
    }
};