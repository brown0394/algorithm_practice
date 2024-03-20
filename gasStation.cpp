#include <iostream>
#include <vector>

int main() {
	int cities;
	scanf_s("%d", &cities);
	std::vector<int> distances(cities - 1);
	for (int i = 0; i < (cities-1); ++i) {
		scanf_s("%d", &distances[i]);
	}
	std::vector<int> gasCosts(cities);
	for (int i = 0; i < cities; ++i) {
		scanf_s("%d", &gasCosts[i]);
	}
	long long sum = 0;
	long long lastCost = gasCosts[0];
	int lastIdx = 0;
	for (int i = 1; i < cities; ++i) {
		if (gasCosts[i] < lastCost) {
			for (; lastIdx < i; ++lastIdx) {
				sum += (lastCost * distances[lastIdx]);
			}
			lastCost = gasCosts[i];
		}
	}
	for (; lastIdx < (cities-1); ++lastIdx) {
		sum += (lastCost * distances[lastIdx]);
	}
	printf("%lld\n", sum);
}
