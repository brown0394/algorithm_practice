class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<array<int, 26>> alphaCounts(words1.size());
        array<int, 26> alphaCounts2 {};
        for (int i = 0, len = words2.size(); i < len; ++i)
        {
            array<int, 26> tempCounts {};
            for (int j = 0, len2 = words2[i].size(); j < len2; ++j)
            {
                ++tempCounts[words2[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j)
            {
                alphaCounts2[j] = max(alphaCounts2[j], tempCounts[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < words1.size(); ++i) 
        {
            for (int j = 0, len2 = words1[i].size(); j < len2; ++j)
            {
                ++alphaCounts[i][words1[i][j]-'a'];
            }
            bool isUniversal = true;
            for (int j = 0; j < 26; ++j)
            {
                if (alphaCounts[i][j] < alphaCounts2[j])
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