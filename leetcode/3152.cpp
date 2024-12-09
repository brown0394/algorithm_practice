class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> falseIdx;
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] % 2 == nums[i+1] % 2) falseIdx.push_back(i);
        }
        size = queries.size();
        vector<vector<int>> qs;
        qs.reserve(size);
        for (int i = 0; i < size; ++i) {
            qs.push_back(queries[i]);
            qs[i].push_back(i);
        }
        sort(qs.begin(), qs.end());
        int idx = 0;
        int fsize = falseIdx.size();
        vector<bool> ans(size);
        
        for (int a : falseIdx) cout << a << endl;
        for (int i = 0; i < size; ++i) {
            while (idx < fsize && falseIdx[idx] < qs[i][0]) ++idx;
            if (idx == fsize) {
                ans[qs[i][2]] = true;
                continue;
            }
            if (falseIdx[idx] + 1 <= qs[i][1]) ans[qs[i][2]] = false;
            else ans[qs[i][2]] = true;
        }
        return ans;
    }
};