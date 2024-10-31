class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> valid(s.size());
        stack<int> stk;
        for (int i = 0, len = s.size(); i < len; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (!stk.empty()) {
                    valid[stk.top()] = true;
                    stk.pop();
                    valid[i] = true;
                }
            }
        }
        int longest = 0;
        int count = 0;
        for (int i = 0, len = valid.size(); i < len; ++i) {
            if (valid[i]) ++count;
            else {
                longest = max(longest, count);
                count = 0;
            }
        }
        longest = max(longest, count);
        return longest;
    }
};