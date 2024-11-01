class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        bool combo = false;
        ans.push_back(s[0]);
        for (int i = 1, len = s.size(); i < len; ++i) {
            if (s[i] == s[i-1]) {
                if (!combo) {
                    combo = true;
                    ans.push_back(s[i]);
                }
            }
            else {
                combo = false;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};