#include <iostream>
#include <vector>
#include <limits>

struct node {
	int to, idx;
};
std::vector<std::vector<node>> infos;
int regions, period;
const long long inf = std::numeric_limits<long long>::max();
long long getMinTime(int from, int idx, long long sum) {
	if (from == 1) return sum + idx;
	long long min = inf;
	long long cur = inf;
	for (auto it = infos[from].begin(), end = infos[from].end(); it != end; ++it) {
		long long next;
		if (it->idx < idx) {
			next = idx - it->idx;
		}
		else {
			next = (idx + period) - it->idx;
		}
		next += sum;
		cur = getMinTime(it->to, it->idx, next);
		if (cur < min) {
			printf("%d %d\n", it->idx, idx);
			min = cur;
		}
	}
	return min;
}
int main() {
	
	scanf_s("%d %d", &regions, &period);

	infos.resize(regions + 1, std::vector<node>((period / regions) + 1));
	int from, to;
	for (int i = 1; i <= period; ++i) {
		scanf_s("%d %d", &from, &to);
		if (from > to) infos[from].emplace_back(node{ to, i });
		else infos[to].emplace_back(node{ from, i });
	}
	long long min = inf;
	long long cur = inf;
	for (auto it = infos[regions].begin(), end = infos[regions].end(); it != end; ++it) {
		printf("\n");
		cur = getMinTime(it->to, it->idx, 0);
		if (cur < min) min = cur;
		printf("%d\n", min);
	}
	printf("%lld\n", min);
}