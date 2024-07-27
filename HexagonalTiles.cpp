#include <iostream>

int main() {
	int daysNeeded[50]{1, 2, 3};
	int curLen = 3;
	while (true) {
		int num;
		scanf_s("%d", &num);
		if (!num) break;
		if (num > curLen) {
			for (; curLen < num; ++curLen) {
				daysNeeded[curLen] = daysNeeded[curLen - 1] + daysNeeded[curLen - 2];
			}
		}
		printf("%d\n", daysNeeded[num - 1]);
	}
}