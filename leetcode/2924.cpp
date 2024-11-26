class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> haveStronger(n, false);
        for (int i = 0, len = edges.size(); i < len; ++i) {
            haveStronger[edges[i][1]] = true;
        }
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (!haveStronger[i]) {
                if (idx >= 0) return -1;
                idx = i;
            }
        }
        return idx;
    }
};