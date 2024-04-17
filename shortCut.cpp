#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int start;
	int end;
	int km;
	bool operator < (const node& other) {
		if (start == other.start) {
			if (end == other.end) {
				return km < other.km;
			}
			return end > other.end;
		}
		return start < other.start;
	}
};

int main() {
	int totalLen, shortCut;
	scanf_s("%d %d", &shortCut, &totalLen);
	std::vector<node> shortCuts;
	const int MAX = totalLen + 10;
	std::vector<int> road(totalLen + 1, MAX);
	node in;
	for (int i = 0; i < shortCut; ++i) {
		scanf_s("%d %d %d", &in.start, &in.end, &in.km);
		if (in.end <= totalLen) shortCuts.emplace_back(in);
	}
	std::sort(shortCuts.begin(), shortCuts.end());
	road[0] = 0;
	int idx = 1;
	for (auto it = shortCuts.begin(); it != shortCuts.end(); ++it) {
		while (idx <= it->start) {
			if (road[idx] > road[idx - 1] + 1) road[idx] = road[idx - 1] + 1;
			++idx;
		}
		if (road[it->start] + it->km < road[it->end]) {
			road[it->end] = road[it->start] + it->km;
		}
	}
	while (idx <= totalLen) {
		if (road[idx] > road[idx - 1] + 1) road[idx] = road[idx - 1] + 1;
		++idx;
	}
	printf("%d\n", road[totalLen]);
}