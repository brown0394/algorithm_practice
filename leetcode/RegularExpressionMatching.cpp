#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*') {
                int til = i + 1;
                for (; til < p.size(); ++til) {
                    if (p[til] != '*') break;
                }
                --til;
                p.erase(i + 1, til - i);
            }
        }
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = true;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*') {
                if (i == 1) dp[0][i + 1] = true;
                else dp[0][i + 1] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    if (j < 2) continue;
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == '.' || (p[j - 2] == s[i - 1] && dp[i][j-1]));
                }
            }
        }
        return dp.back().back();
    }
};