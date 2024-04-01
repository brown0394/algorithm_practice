#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int idx;
	int val;
	bool operator <(const node& other) {
		return val > other.val;
	}
};

long long getMaxProfit(std::vector<int>& rates, int start, int end) {
	long long maxProfit = 0;
	for (int k = start; k < end; ++k) {
		maxProfit += (rates[end] - rates[k]);
	}
	return maxProfit;
}

int main() {
	int testCases, days;
	scanf_s("%d", &testCases);
	std::vector<int> rates;
	std::vector<node> ratesSorted;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &days);
		rates.resize(days);
		ratesSorted.resize(days);
		int incrStart = 0;
		long long maxProfit = 0;
		for (int j = 0; j < days; ++j) {
			scanf_s("%d", &rates[j]);
			ratesSorted[j].idx = j;
			ratesSorted[j].val = rates[j];
		}
		std::sort(ratesSorted.begin(), ratesSorted.end());
		int last = 0;
		for (int j = 0; j < days; ++j) {
			if (ratesSorted[j].idx >= last) {
				maxProfit += getMaxProfit(rates, last, ratesSorted[j].idx);
				last = ratesSorted[j].idx + 1;
			}
		}
		printf("%lld\n", maxProfit);
	}

}