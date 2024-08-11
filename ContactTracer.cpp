#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while (true) {
		int users, contacts, firstInfected;
		std::cin >> users >> contacts >> firstInfected;
		if (!users && !contacts && !firstInfected) break;
		std::vector<bool> infected(users + 1);
		infected[firstInfected] = true;
		int totalInfected = 1;
		for (int i = 0, one, two; i < contacts; ++i) {
			std::cin >> one >> two;
			if (infected[one]) {
				if (infected[two]) continue;
				infected[two] = true;
				++totalInfected;
			}
			else if (infected[two]) {
				infected[one] = true;
				++totalInfected;
			}
		}
		std::cout << totalInfected << '\n';
	}
}