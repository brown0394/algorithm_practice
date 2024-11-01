class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        
        if (l == nums.end() || *l != target) return {-1, -1};
        return {static_cast<int>(l - nums.begin()), static_cast<int>(r - nums.begin() - 1)};
    }
};