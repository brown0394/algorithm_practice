class Solution {
    int combinations[101];
    int len;
    vector<vector<int>> ans;
    void tryCombination(vector<int>& candidates, int target, int idx, int sum, int combiIdx) {
        if (target == sum) {
            ans.push_back({});
            ans.back().resize(combiIdx);
            vector<int>& v = ans.back();
            for (int i = 0; i < combiIdx; ++i) v[i] = combinations[i];
            return;
        }
        if (idx >= len) return;
        if (target >= sum + candidates[idx]) {
            combinations[combiIdx] = candidates[idx];
            tryCombination(candidates, target, idx + 1, sum + candidates[idx], combiIdx + 1);
        }
        ++idx;
        while (idx < len && candidates[idx] == candidates[idx-1]) ++idx;
        tryCombination(candidates, target, idx, sum, combiIdx);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        len = candidates.size();
        tryCombination(candidates, target, 0, 0, 0);
        return ans;
    }
};