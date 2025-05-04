class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, unordered_map<int, int>> counts;
        for (int i = 0, size = dominoes.size(); i < size; ++i)
        {
            pair<int, int> p;
            if (dominoes[i][0] > dominoes[i][1])
                swap(dominoes[i][0], dominoes[i][1]);
            
            ++(counts[dominoes[i][0]][dominoes[i][1]]);
        }
        int ans = 0;
        for (auto it1 = counts.begin(); it1 != counts.end(); ++it1)
        {
            auto itEnd = it1->second.end();
            for (auto it2 = it1->second.begin(); it2 != itEnd; ++it2)
            {
                int num = it2->second;
                ans += ((num * (num-1)) >> 1);
            }
        }
        return ans;
    }
};