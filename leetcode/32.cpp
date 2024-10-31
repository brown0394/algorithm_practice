class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int longest = 0;
        stk.push(-1);
        for (int i = 0, len = s.size(); i < len; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (!stk.empty()) {
                    longest = max(longest, i - stk.top());
                }
                else {
                    stk.push(i);
                }
            }
        }
        return longest;
    }
};