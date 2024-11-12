class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> maxBeauty;
        maxBeauty.push_back({items[0][0], items[0][1]});
        for (int i = 1, size = items.size(), cur = 0; i < size; ++i) {
            if (maxBeauty[cur].first == items[i][0]) {
                maxBeauty[cur].second = max(maxBeauty[cur].second, items[i][1]);
            }
            else {
                maxBeauty.push_back({items[i][0], items[i][1]});
                ++cur;
                maxBeauty[cur].second = max(maxBeauty[cur].second, maxBeauty[cur-1].second);
            }
        }
        vector<int> ans(queries.size());
        auto comp = [](pair<int, int>& p, int v) {
            return p.first < v;
        };
        for (int i = 0, size = queries.size(); i < size; ++i) {
            auto found = lower_bound(maxBeauty.begin(), maxBeauty.end(), queries[i], comp);
            if (found == maxBeauty.end()) --found;
            if (found->first > queries[i]) {
                if (found == maxBeauty.begin()) {
                    ans[i] = 0;
                    continue;
                }
                --found;
            }
            ans[i] = found->second;
        }
        return ans;
    }
};