class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLen = words[0].size();
        int modVal = 1000000007;
        vector<vector<int>> alphaCounts(wordLen, vector<int>(26));
        for (string& str : words) {
            for (int i = 0; i < wordLen; ++i) {
                ++alphaCounts[i][str[i]-'a'];
            }
        }
        int targetLen = target.size();
        vector<vector<long long>> dp(targetLen, vector<long long>(wordLen));
        for (int i = 0, til = wordLen - targetLen, t = target[0]-'a'; i <= til; ++i) {
            dp[0][i] = alphaCounts[i][t];
            if (i) dp[0][i] += dp[0][i-1];
        }
        for (int i = 1; i < targetLen; ++i) {
            int t = target[i] - 'a';
            int til = wordLen - (targetLen - i);
            for (int j = i; j <= til; ++j) {
                dp[i][j] = (alphaCounts[j][t] * dp[i-1][j-1] + dp[i][j-1]) % modVal;
            }
        }
        return dp[targetLen-1][wordLen-1];
    }
};