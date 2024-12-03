class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = s.substr(0, spaces[0]);
        int last = spaces[0];
        for (int i = 1, len = spaces.size(); i < len; ++i) {
            ans.push_back(' ');
            ans += s.substr(last, spaces[i] - last);
            last = spaces[i];
        }
        if (last < s.size()) {
            ans.push_back(' ');
            ans += s.substr(last, s.size() - last);
        }
        return ans;
    }
};