#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> houseLocs;
int routers, houses;
bool check(int dist) {
	int count = 1;
	int cur = 0;
	for (int i = 1; i < houses; ++i) {
		if ((houseLocs[i] - houseLocs[cur]) >= dist) {
			cur = i;
			if (++count == routers) return true;
		}
	}
	return false;
}

int main() {
	scanf_s("%d %d", &houses, &routers);
	houseLocs.resize(houses);
	for (int i = 0; i < houses; ++i) scanf_s("%d", &houseLocs[i]);
	std::sort(houseLocs.begin(), houseLocs.end());
	long long low = 0;
	long long high = houseLocs.back();
	long long mid;
	while (low < high) {
		mid = (low + high + 1) >> 1;
		if (check(mid)) {
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}
	if (check(low)) printf("%lld\n", low);
}
