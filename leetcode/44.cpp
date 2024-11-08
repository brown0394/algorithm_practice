class Solution {
    vector<vector<int>> dp;
    int len1, len2;
    bool tryPossibility(string &s, string &p, int i, int j) {
        if (i == len1) {
            while (j < len2 && p[j] == '*') ++j;
            if (j == len2) return true;
            return false; 
        }
        if (j == len2) return false;
        if (dp[i][j] >= 0) return dp[i][j];
        if (p[j] == '?') return dp[i][j] = tryPossibility(s, p, i + 1, j + 1);
        if (p[j] == '*') {
            return dp[i][j] = tryPossibility(s, p, i+1, j) || tryPossibility(s, p, i, j+1);
        }
        if (s[i] != p[j]) return dp[i][j] = false;
        return dp[i][j] = tryPossibility(s, p, i + 1, j + 1);
    }
public:
    bool isMatch(string s, string p) {
        len1 = s.size();
        len2 = p.size();
        dp.resize(len1, vector<int>(len2, -1));
        return tryPossibility(s, p, 0, 0);
    }
};