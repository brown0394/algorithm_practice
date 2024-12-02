class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        auto it = intervals.begin(), end = intervals.end();
        while (it != end) {
            ans.push_back({(*it)[0], (*it)[1]});
            ++it;
            while (it != end && (*it)[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], (*it)[1]);
                ++it;
            }
        }
        return ans;
    }
};