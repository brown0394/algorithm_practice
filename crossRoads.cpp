#include <iostream>
#include <vector>
#include <limits>
#include <queue>

const long long inf = std::numeric_limits<long long>::max();
struct node {
	node(long long p_cost = inf, int p_idx = -1, int p_to = -1) :
		cost(p_cost), idx(p_idx), to(p_to) {}
	long long cost;
	int idx;
	int to;
};
std::vector<std::vector<node>> infos;
std::vector<node> startP;
int regions, period;

int main() {
	scanf_s("%d %d", &regions, &period);
	infos.resize(regions + 1);
	startP.resize(regions + 1);
	int from, to;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 1; i <= period; ++i) {
		scanf_s("%d %d", &from, &to);
		if (from == 1) {
			if (startP[to].cost < inf) continue;
			startP[to].cost = startP[to].idx = i;
			pq.push(to);
		}
		else if (to == 1) {
			if (startP[from].cost < inf) continue;
			startP[from].cost = startP[from].idx = i;
			pq.push(from);
		}
		else {
			infos[from].emplace_back(i, i, to);
			infos[to].emplace_back(i, i, from);
		}
	}
	startP[1].cost = 0;
	while (!pq.empty()) {
		int idx = pq.top();
		pq.pop();
		for (auto it = infos[idx].begin(), end = infos[idx].end(); it != end; ++it) {
			long long toCost = 0;
			if (it->idx > startP[idx].idx) {
				toCost = (it->idx - startP[idx].idx);
			}
			else {
				toCost = ((it->idx + period) - startP[idx].idx);
			}
			toCost += startP[idx].cost;
			if (toCost < startP[it->to].cost) {
				startP[it->to].cost = toCost;
				startP[it->to].idx = it->idx;
				pq.push(it->to);
			}
		}
	}

	printf("%lld\n", startP[regions].cost);
}