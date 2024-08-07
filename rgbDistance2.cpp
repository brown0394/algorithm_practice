#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int houses;
	const int INF = 1000000000;
	std::cin >> houses;
	std::vector<std::vector<int>> costs(houses, std::vector<int>(3));
	for (int i = 0; i < houses; ++i) {
		std::cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
	}
	int len = houses - 1;
	std::vector<std::vector<int>> dp(len, std::vector<int>(3));
	
	int min = INF;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (j == i) {
				dp[0][j] = INF;
			}
			else dp[0][j] = costs[0][i] + costs[1][j];
		}
		for (int j = 1; j < len-1; ++j) {
			for (int k = 0; k < 3; ++k) {
				int idx1 = (k + 1) % 3, idx2 = (k + 2) % 3;
				if (dp[j - 1][idx1] > dp[j - 1][idx2]) {
					dp[j][k] = dp[j - 1][idx2] + costs[j+1][k];
				}
				else {
					dp[j][k] = dp[j - 1][idx1] + costs[j + 1][k];
				}
			}
		}
		if (len > 1) {
			for (int j = 0; j < 3; ++j) {
				if (j == i) {
					dp[len - 1][j] = INF;
					continue;
				}
				int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;
				if (dp[len - 2][idx1] > dp[len - 2][idx2]) {
					dp[len - 1][j] = dp[len - 2][idx2] + costs[len][j];
				}
				else {
					dp[len - 1][j] = dp[len - 2][idx1] + costs[len][j];
				}
			}
		}
		for (int j = 0; j < 3; ++j) {
			if (dp[len - 1][j] < min) min = dp[len - 1][j];
		}
	}
	std::cout << min << std::endl;
}