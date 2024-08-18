#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int mem, cost;
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int runningApps, memNeeded;
	const int MAX = 1000000000;
	std::cin >> runningApps >> memNeeded;
	std::vector<node> appInfos(runningApps + 1);
	for (int i = 1; i <= runningApps; ++i) std::cin >> appInfos[i].mem;
	for (int i = 1; i <= runningApps; ++i) std::cin >> appInfos[i].cost;
	std::vector<std::vector<int>> knapsackDP(memNeeded + 1, std::vector<int>(runningApps + 1, MAX));
	for (int mem = 1; mem <= memNeeded; ++mem) {
		for (int i = 1; i <= runningApps; ++i) {
			knapsackDP[mem][i] = knapsackDP[mem][i - 1];
			if (mem >= appInfos[i].mem) {
				if (knapsackDP[mem - appInfos[i].mem][i - 1] == MAX) {
					if (appInfos[i].cost < knapsackDP[mem][i]) {
						knapsackDP[mem][i] = appInfos[i].cost;
					}
				}
				else {
					if (knapsackDP[mem][i] > knapsackDP[mem - appInfos[i].mem][i - 1] + appInfos[i].cost) {
						knapsackDP[mem][i] = knapsackDP[mem - appInfos[i].mem][i - 1] + appInfos[i].cost;
					}
				}

			}
		}
	}
	std::cout << knapsackDP[memNeeded][runningApps] << '\n';
}