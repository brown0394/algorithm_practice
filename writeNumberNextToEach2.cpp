#include <iostream>

int main() {
	int n, nth;
	scanf("%d", &n, &nth);
	int digits[]{ 0, 9, 90, 900, 9000, 90000, 900'000, 9'000'000, 90'000'000 };
	long long base = 9;
	if (n < 10) printf("%d\n", n);
	else {
		for (int i = 2; i <= 8; ++i) {
			if (nth <= digits[i] * i) {
				nth -= digits[i - 1] * (i - 1);
			}
		}
		long long sum = 0;
		int digit = 10;
		int check;
		for (int i = 1; i <= 9; ++i) {
			check = n / digit;
			if (!check) {
				digit /= 10;
				sum += ((n / digit) - 1) * digit * i;
				sum += ((n % digit) + 1) * i;
				break;
			}
			else {
				sum += (base * i);
				base *= 10;
				digit *= 10;

			}
		}
		printf("%lld\n", sum);
	}
}
