class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        int common = strs[0].size();
        for (int i = 1, len = strs.size(); i < len; ++i) {
            int count = 0;
            for (int j = 0, l = strs[i].size(); j < common && j < common; ++j) {
                if (strs[i][j] != strs[i-1][j]) {
                    common = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, common);
    }
};