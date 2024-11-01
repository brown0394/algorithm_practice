class Solution {
    int combinations[151];
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
        tryCombination(candidates, target, idx + 1, sum, combiIdx);
        while (sum + candidates[idx] <= target) {
            sum += candidates[idx];
            combinations[combiIdx++] = candidates[idx];
            tryCombination(candidates, target, idx + 1, sum, combiIdx);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        len = candidates.size();
        tryCombination(candidates, target, 0, 0, 0);
        return ans;
    }
};