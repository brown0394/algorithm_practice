class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<int> ans(2);

        set<int> checks;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                auto found = checks.find(grid[i][j]);
                if (found != checks.end())
                {
                    ans[0] = *found;
                    continue;
                }
                checks.insert(grid[i][j]);
            }
        }
        auto cur = checks.begin();
        if (*cur != 1)
        {
            ans[1] = 1;
            return ans;
        }
        int last = 1;
        ++cur;
        while (cur != checks.end())
        {
            if (*cur - last > 1)
                break;
            ++cur;
            ++last;
        }
        ans[1] = last+1;
        return ans;
    }
};