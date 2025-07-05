class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int size = nums.size();
        vector<pair<int, int>> v(size);
        for (int ii = 0; ii < size; ++ii)
        {
            v[ii].first = nums[ii];
            v[ii].second = ii;
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());
        sort(v.begin(), v.begin()+k, [](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });
        vector<int> ans(k);
        for (int ii = 0; ii < k; ++ii)
        {
            ans[ii] = v[ii].first;
        }

        return ans;
    }
};
