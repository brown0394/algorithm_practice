#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct info {
	int weight, value;
	bool operator <(const info& other) {
		if (weight == other.weight) {
			return value < other.value;
		}
		return weight < other.weight;
	}
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int jewels, bags;
	std::cin >> jewels >> bags;
	std::vector<info> jewelInfos(jewels);
	for (int i = 0; i < jewels; ++i) {
		std::cin >> jewelInfos[i].weight >> jewelInfos[i].value;
	}
	std::vector<int> bagWeights(bags);
	for (int i = 0; i < bags; ++i) {
		std::cin >> bagWeights[i];
	}
	std::sort(bagWeights.begin(), bagWeights.end());
	std::sort(jewelInfos.begin(), jewelInfos.end());
	long long totalVal = 0;
	std::priority_queue<int> pq;
	int idx = 0, len = jewelInfos.size();
	for (auto it = bagWeights.begin(), end = bagWeights.end(); it != end; ++it) {
		while (idx < len && jewelInfos[idx].weight <= *it) {
			pq.push(jewelInfos[idx++].value);
		}
		if (pq.empty()) continue;
		totalVal += pq.top();
		pq.pop();
	}
	std::cout << totalVal << '\n';
}