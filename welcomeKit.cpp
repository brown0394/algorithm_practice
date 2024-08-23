#include <iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int partcipants;
	std::cin >> partcipants;
	int clothOrders[6];
	for (int i = 0; i < 6; ++i) {
		std::cin >> clothOrders[i];
	}
	int tshirtG, penG;
	std::cin >> tshirtG >> penG;
	int totalTshirtG = 0;
	for (int i = 0; i < 6; ++i) {
		totalTshirtG += (clothOrders[i] / tshirtG);
		if (clothOrders[i] % tshirtG) ++totalTshirtG;
	}
	int totalPenG = partcipants / penG;
	int penIndiv = partcipants - (totalPenG * penG);
	std::cout << totalTshirtG << '\n' << totalPenG << ' ' <<
		penIndiv << '\n';
}