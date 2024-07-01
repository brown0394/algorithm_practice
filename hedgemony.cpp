#include <iostream>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	double first, second, third;
	for (int i = 1; i <= testCases; ++i) {
		int nums;
		scanf_s("%d", &nums);
		scanf_s("%lf %lf", &first, &second);
		int idx = 2;
		while (idx++ < nums) {
			scanf_s("%lf", &third);
			double mean = (first + third) / 2;
			if (second >= mean) first = mean;
			else first = second;
			second = third;
		}
		printf("Case #%d: %lf\n", i, first);
	}
}