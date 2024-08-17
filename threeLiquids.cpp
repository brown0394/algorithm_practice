#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int len;
	std::cin >> len;
	std::vector<long long> liquids(len);
	for (int i = 0; i < len; ++i) {
		std::cin >> liquids[i];
	}
	std::sort(liquids.begin(), liquids.end());
	long long min = std::numeric_limits<long long>::max();
	long long minComb[3]{ 0 };
	long long curComb[3]{ 0 };
	for (int i = 0; i < len; ++i) {
		int begin = 0;
		int end = len - 1;
		long long curMin = min;
		while (begin < end) {
			if (begin == i) {
				++begin;
				continue;
			}
			if (end == i) {
				--end;
				continue;
			}
			long long calc = liquids[i] + liquids[begin] + liquids[end];
			long long calcAbs = std::abs(calc);
			if (calcAbs < curMin) {
				curComb[0] = liquids[begin];
				curComb[1] = liquids[i];
				curComb[2] = liquids[end];
				curMin = calcAbs;
				if (curMin == 0) break;
			}
			if (calc < 0) ++begin;
			else --end;
		}
		if (curMin < min) {
			minComb[0] = curComb[0];
			minComb[1] = curComb[1];
			minComb[2] = curComb[2];
			min = curMin;
			if (min == 0) break;
		}
	}
	std::sort(minComb, minComb + 3);
	std::cout << minComb[0] << ' ' << minComb[1] << ' ' << minComb[2] << '\n';
}