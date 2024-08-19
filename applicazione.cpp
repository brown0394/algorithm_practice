#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int runningApps, memNeeded;
	std::cin >> runningApps >> memNeeded;
	std::vector<int> memInfo(runningApps + 1);
	std::vector<int> costInfo(runningApps + 1);
	for (int i = 1; i <= runningApps; ++i) std::cin >> memInfo[i];
	int maxCost = 0;
	for (int i = 1; i <= runningApps; ++i) {
		std::cin >> costInfo[i];
		maxCost += costInfo[i];
	}
	
	std::vector<std::vector<int>> knapsackDP(maxCost + 1, std::vector<int>(runningApps + 1, 0));
	for (int cost = 0; cost <= maxCost; ++cost) {
		for (int i = 1; i <= runningApps; ++i) {
			knapsackDP[cost][i] = knapsackDP[cost][i - 1];
			if (costInfo[i] <= cost && knapsackDP[cost][i] < knapsackDP[cost - costInfo[i]][i - 1] + memInfo[i]) {
				knapsackDP[cost][i] = knapsackDP[cost - costInfo[i]][i - 1] + memInfo[i];
				if (knapsackDP[cost][i] >= memNeeded) {
					std::cout << cost << '\n';
					return 0;
				}
			}
		}
	}
}