#include <iostream>

int main() {
	long long num;
	scanf_s("%lld", &num);
	bool possible = false;
	if (num == 1) {
		printf("no\n");
		return 0;
	}
	for (long long i = 2; i * i <= num; ++i) {
		if (!(num % i)) {
			long long p = i;
			while (p < num) p *= i;
			if (p == num) {
				printf("yes\n");
				return 0;
			}
			else {
				printf("no\n");
				return 0;
			}
		}
	}
	printf("yes\n");
}