#include <iostream>

int main() {
	int min = ~(1 << 31);
	int in;
	int sum = 0;
	for (int i = 0; i < 7; ++i) {
		scanf_s("%d", &in);
		if (in % 2 == 1) {
			if (min > in) min = in;
			sum += in;
		}
	}
	if (min < ~(1 << 31)) printf("%d\n%d\n", sum, min);
	else printf("-1\n");
}
