class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<unordered_map<char, int>> alphaCounts(words1.size());
        unordered_map<char, int> alphaCounts2;
        for (int i = 0; i < words1.size(); ++i)
        {
            for (char c : words1[i])
            {
                ++alphaCounts[i][c];
            }
        }
        for (int i = 0; i < words2.size(); ++i)
        {
            unordered_map<char, int> tempCounts;
            for (char c : words2[i])
            {
                ++tempCounts[c];
            }
            for (pair<const char, int>& p : tempCounts)
            {
                alphaCounts2[p.first] = max(alphaCounts2[p.first], p.second);
            }
        }
        vector<string> ans;
        for (int i = 0; i < alphaCounts.size(); ++i) 
        {
            bool isUniversal = true;
            for (pair<const char, int>& p : alphaCounts2)
            {
                if (alphaCounts[i][p.first] < p.second)
                {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal == true)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};