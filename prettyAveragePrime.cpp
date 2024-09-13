#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int testCases;
	std::cin >> testCases;
	std::bitset<2000001> aristones;
	aristones[0] = true;
	aristones[1] = true;
	for (int i = 2; (i * i) <= 2000000; ++i) {
		if (!aristones[i]) {
			int mult = i;
			while (i * mult <= 2000000) {
				aristones[i * mult] = true;
				++mult;
			}
		}
	}
	std::vector<int> primes;
	for (int i = 2; i <= 2000000; ++i) {
		if (!aristones[i]) primes.push_back(i);
	}
	for (int i = 0, target; i < testCases; ++i) {
		std::cin >> target;
		target <<= 1;
		auto upper = std::lower_bound(primes.begin(), primes.end(), target);
		if (upper == primes.end()) --upper;
		auto lower = primes.begin();
		while (*lower < *upper) {
			if (*lower + *upper == target) {
				std::cout << *lower << ' ' << *upper << '\n';
				break;
			}
			else if (*lower + *upper > target) --upper;
			else ++lower;
		}
	}
}