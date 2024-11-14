class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> pairs(strs.size());
        for (int i = 0, len = strs.size(); i < len; ++i) {
            pairs[i].first = strs[i];
            sort(pairs[i].first.begin(), pairs[i].first.end());
            pairs[i].second = i;
        }
        sort (pairs.begin(), pairs.end());
        int size = pairs.size();
        int idx = 1;
        vector<vector<string>> ans;
        ans.push_back({strs[pairs[0].second]});
        while (idx < size) {
            if (pairs[idx].first == pairs[idx-1].first) {
                ans.back().push_back(strs[pairs[idx].second]);
            }
            else ans.push_back({strs[pairs[idx].second]});
            ++idx;
        }
        return ans;
    }
};