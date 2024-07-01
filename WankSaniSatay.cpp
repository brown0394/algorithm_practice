#include <iostream>

int main() {
	const float chickenP = 0.8;
	const float BeefP = 1;
	const float LambP = 1.2;
	const float nasiP = 0.8;
	const float satayPerKg = 85;
	const float chickenMP = 15.5;
	const float beefMP = 32;
	const float lambMP = 40;
	const float nasiMP = 0.2;
	const float marinate = 8;
	int days;
	int caseN = 1;
	while (true) {
		scanf_s("%d", &days);
		if (!days) break;
		int c, b, l, n;
		int totc = 0, totb = 0, totl = 0, totn = 0;
		double totalEarned = 0, totalSpent = 0;
		for (int i = 0; i < days; ++i) {
			scanf_s("%d %d %d %d", &c, &b, &l, &n);
			totc += c; totb += b; totl += l; totn += n;
		}
		totalEarned = (totc * chickenP) + (totb * BeefP) + (totl * LambP) + (totn * nasiP);
		double meatUsed;
		totalSpent += (totc / satayPerKg) * chickenMP;
		totalSpent += (totb / satayPerKg) * beefMP;
		totalSpent += (totl / satayPerKg) * lambMP;
		totalSpent += (totn * nasiMP);

		printf("Case #%d: RM%.2lf\n", caseN++, totalEarned - totalSpent);
	}
}