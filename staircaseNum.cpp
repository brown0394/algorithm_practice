#include <iostream>
#include <vector>
#include <bitset>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int len;
    std::cin >> len;
    short int val[10]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    int target = 0x3ff;
    int cap = 1000000000;
    std::vector<std::vector<std::vector<long long>>> dp(len, std::vector<std::vector<long long>>(10,
        std::vector<long long>(0x400)));
    for (int i = 1; i <= 9; ++i) dp[0][i][val[i]] = 1;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 1; k < 0x400; ++k) {
                int cur = k | val[j];
                if (j) dp[i][j][cur] += dp[i - 1][j - 1][k];
                if (j < 9) dp[i][j][cur] += dp[i - 1][j + 1][k];
                dp[i][j][cur] %= cap;
            }
        }
    }
    long long ans = 0;
    --len;
    for (int i = 0; i <= 9; ++i) {
        ans += dp[len][i][target];
        ans %= cap;
    }
    std::cout << ans << '\n';
}