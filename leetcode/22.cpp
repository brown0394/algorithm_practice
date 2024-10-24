class Solution {
    vector<string> ans;
    int till;
    void combination(string& s, int open, int close) {
        if (close == till) {
            ans.push_back(s);
            return;
        }
        if (open < till) {
            s.push_back('(');
            combination(s, open + 1, close);
            s.pop_back();
        }
        if (close < till && open > close) {
            s.push_back(')');
            combination(s, open, close + 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        till = n;
        string s;
        combination(s, 0, 0);
        return ans;
    }
};