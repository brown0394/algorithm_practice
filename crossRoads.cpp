#include <iostream>
#include <vector>
#include <limits>

struct node {
	int to, idx;
};
std::vector<std::vector<node>> infos;
int regions, period;
const long long inf = std::numeric_limits<long long>::max();
int getMinTime(int from, int idx, long long sum) {
	if (from == 1) return sum;
	long long min = inf;
	long long cur = 0;
	for (auto it = infos[from].begin(), end = infos[from].end(); it != end; ++it) {
		if (it->idx > idx) {
			cur = getMinTime(it->to, it->idx, sum + (it->idx - idx));
		}
		else {
			cur = getMinTime(it->to, it->idx, sum + ((it->idx + period) - idx));
		}
		if (cur < min) min = cur;
	}
	return min;
}
int main() {
	
	scanf_s("%d %d", &regions, &period);

	infos.resize(regions + 1);
	int from, to;
	for (int i = 1; i <= period; ++i) {
		scanf_s("%d %d", &from, &to);
		if (from > to) infos[from].emplace_back(node{ to, i });
		else infos[to].emplace_back(node{ from, i });
	}
	long long min = inf;
	long long cur = 0;
	for (auto it = infos[regions].begin(), end = infos[regions].end(); it != end; ++it) {
		cur = getMinTime(it->to, it->idx, it->idx);
		if (cur < min) min = cur;
	}
	printf("%lld\n", min+1);
}