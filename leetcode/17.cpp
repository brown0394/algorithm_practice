class Solution {
    char mappings[8][5] {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> ans;
    void combinations(string& digits, int idx, string s) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }
        int cur = digits[idx] - '0' - 2;
        for (int i = 0; mappings[cur][i] != '\0'; ++i) {
            combinations(digits, idx + 1, s + mappings[cur][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        combinations(digits, 0, "");
        return ans;
    }
};