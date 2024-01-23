#include <iostream>

int main() {
	int n;
	scanf_s("%d", &n);
	int digits[]{ 9, 90, 900, 9000, 90000 };
	long long base = 9;
	if (n < 10) printf("%d\n", n);
	else {
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
