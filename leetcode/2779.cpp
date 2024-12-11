class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto comp = [k](int v, int v2) {
            return v < v2 - k;
        };
        int maxV = 0;
        int n = nums.size();
        for (auto it = nums.begin(), end = nums.end(); it != end; ++it) {
            auto found = upper_bound(it, end, *it + k, comp);
            int count = 0;
            if (found == end) {
                count = n - (it - nums.begin());
            }
            else count = found - it;
            maxV = max(maxV, count);
        }
        return maxV;
    }
};