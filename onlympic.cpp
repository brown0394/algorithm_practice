#include <iostream>
#include <vector>
#include <algorithm>

struct medal {
	int num;
	int gold;
	int silver;
	int bronze;
	bool operator < (const medal& other) {
		if (gold == other.gold) {
			if (silver == other.silver) return bronze > other.bronze;
			return silver > other.silver;
		}
		return gold > other.gold;
	}
};

int main() {
	int countries, target;
	scanf_s("%d %d", &countries, &target);
	std::vector<medal> country(countries);
	for (int i = 0; i < countries; ++i) {
		scanf_s("%d %d %d %d", &country[i].num, &country[i].gold,
			&country[i].silver, &country[i].bronze);
	}
	std::sort(country.begin(), country.end());
	for (int i = 0; i < countries; ++i) {
		if (country[i].num == target) {
			for (int j = i - 1; j >= 0; --j) {
				if (country[j].gold > country[i].gold ||
					country[j].silver > country[i].silver ||
					country[j].bronze > country[i].bronze) {
					printf("%d\n", j + 2);
					return 0;
				}
			}
			printf("1\n");
			break;
		}
	}
}
