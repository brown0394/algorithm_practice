#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int totalFruits;
	std::cin >> totalFruits;
	std::vector<int> fruitsIdx(totalFruits);
	for (int i = 0; i < totalFruits; ++i) {
		std::cin >> fruitsIdx[i];
	}
	int l = 0, r = 0, one = 0, two = 0;

	int maxFruits = 0;
	while (l < totalFruits) {
		one = fruitsIdx[l];
		while (r < totalFruits && fruitsIdx[r] == one) ++r;
		if (r == totalFruits) {
			if (maxFruits < r - l) maxFruits = r - l;
			break;
		}
		else {
			int nextL = r;
			int last = 1;
			two = fruitsIdx[r];
			while (r < totalFruits) {
				if (fruitsIdx[r] == two) {
					if (last == 0) {
						nextL = r;
						last = 1;
					}
					++r;
				}
				else if (fruitsIdx[r] == one) {
					if (last) {
						nextL = r;
						last = 0;
					}
					++r;
				}
				else break;
			}
			if (maxFruits < r - l) maxFruits = r - l;
			l = nextL;
			r = l + 1;
		}
	}
	std::cout << maxFruits << '\n';
}