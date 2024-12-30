class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        int modVal = 1000000007;
        int start = min(zero, one);
        dp[zero] += 1;
        dp[one] += 1;
        for (int i = start; i <= high; ++i) {
            if (i-zero >= 0) {
                dp[i] = (dp[i] + dp[i-zero]) % modVal;
            }
            if (i-one >= 0) {
                dp[i] = (dp[i] + dp[i-one]) % modVal;
            }
        }
        int sum = 0;
        for (int i = low; i <= high; ++i) {
            sum = (sum + dp[i]) % modVal;
        }
        return sum;
    }
};