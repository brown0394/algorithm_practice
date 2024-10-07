class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (int i = 0, end = s.size(); i < end; ++i) {
            if (!stk.empty() && ((s[i] == 'B' && stk.top() == 'A') || (s[i] == 'D' && stk.top() == 'C'))) {
               stk.pop();
            }
            else stk.push(s[i]);
        }
        return stk.size();
    }
};