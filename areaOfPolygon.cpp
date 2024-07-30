#include <iostream>

struct coord {
	long long x, y;
};

long long calcDet(coord& c1, coord&c2) {
	return (c1.x * c2.y) - (c2.x * c1.y);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int coords;
	std::cin >> coords;
	coord first, last, cur;
	std::cin >> first.x >> first.y;
	last = first;
	long long detSums = 0;
	for (int i = 1; i < coords; ++i) {
		std::cin >> cur.x >> cur.y;
		detSums += calcDet(last, cur);
		last = cur;
	}
	detSums += calcDet(cur, first);
	double result = detSums / 2.0;
	if (result < 0) result = -result;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << result << '\n';
}