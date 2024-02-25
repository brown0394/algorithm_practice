#include <iostream>

int main() {
	int n, nth;
	scanf_s("%d %d", &n, &nth);
	int digits[9]{ 0, 9, 90, 900, 9000, 90000, 900'000, 9'000'000, 90'000'000 };
	int base = 9;
	if (n < 10) printf("%d\n", n);
	else {
		for (int i = 2; i < 9; ++i) {//10
			digits[i] *= i;
			if (nth <= digits[i]) {
				base = nth - (base + 1);
				int cur = base;
				int count = 0;
				int num = base / i;
				++cur;
				while (base / i == cur / i) ++cur;
				cur -= base;

				int ten = 1;
				for (int j = 1; j < i; ++j) ten *= 10;
				num += ten;
				if (num > n) {
					printf("-1\n");
					break;
				}
				ten = 10;
				for (int j = 1; j < cur; ++j) ten *= 10;
				num = (num % ten) / (ten / 10);
				printf("%d\n", num);
				break;
			}
			base += digits[i];
		}
	}
}
