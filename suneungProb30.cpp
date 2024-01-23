#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int one, two;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d %d", &one, &two);
		while (one != two) {
			if (one > two) {
				if (one % 2) --one;
				one >>= 1;
			}
			else {
				if (two % 2) --two;
				two >>= 1;
			}
		}
		printf("%d\n", one * 10);
	}
}
