#include <iostream>
#include <vector>

int main() {
	int sushiOnBelt, diversity, streak, coupon;
	scanf_s("%d %d %d %d", &sushiOnBelt, &diversity, &streak, &coupon);
	std::vector<int> belt(sushiOnBelt);
	std::vector<int> diversityCount(diversity+1, 0);

	for (int i = 0; i < sushiOnBelt; ++i) {
		scanf_s("%d", &belt[i]);
	}
	int count = 0;
	for (int i = 0; i < streak; ++i) {
		if (!diversityCount[belt[i]]++) ++count;
	}
	int max = count;
	if (!diversityCount[coupon]) ++max;
	--streak;
	for (int i = 1; i > 0; i = (i + 1) % sushiOnBelt) {
		if (!(--diversityCount[belt[i - 1]])) --count;
		if (!(diversityCount[belt[(i + streak) % sushiOnBelt]])++) ++count;
		if (!diversityCount[coupon] && max <= count) max = count + 1;
		else if (max < count) max = count;
	}
	printf("%d\n", max);
}