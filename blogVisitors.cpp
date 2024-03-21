#include <iostream>
#include <vector>

int main() {
	int days, period;
	scanf_s("%d %d", &days, &period);
	std::vector<int> visitors(days);
	for (int i = 0; i < days; ++i) {
		scanf_s("%d", &visitors[i]);
	}
	int sum = 0;
	for (int i = 0; i < period; ++i) {
		sum += visitors[i];
	}
	int til = days - period;
	int max = sum;
	int count = 1;
	for (int i = 0; i < til; ++i) {
		sum -= visitors[i];
		sum += visitors[i + period];
		if (sum == max) ++count;
		else if (sum > max) {
			max = sum;
			count = 1;
		}
	}
	if (!max) printf("SAD\n");
	else printf("%d\n%d\n", max, count);
}
