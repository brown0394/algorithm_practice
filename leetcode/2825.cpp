class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        for (int i = 0, len = str1.size(); i < len; ++i) {
            if (str1[i] == str2[idx] || (str1[i] == 'z' && 'a' == str2[idx]) 
            || str1[i]+1 == str2[idx]) {
                ++idx;
                if (idx == str2.size()) return true;
            }
        }
        return false;
    }
};