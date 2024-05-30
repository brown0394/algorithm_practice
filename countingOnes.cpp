#include <iostream>
#include <vector>

unsigned long long getOnes(unsigned long long *dp, unsigned long long shifted, unsigned long long cur, unsigned long long target) {
	unsigned long long ones = 0, sum = 0;
	do {
		cur >>= 1;
		--shifted;
		if (target & cur) {
			sum += dp[shifted] + 1 + (cur * ones);
			++ones;
		}
	} while (cur > 0);
	return sum;
}

int main() {
	unsigned long long from, to;
	scanf_s("%lld %lld", &from, &to);
	unsigned long long dp[54];
	dp[0] = 0;
	dp[1] = 1;
	unsigned long long last = 2;
	unsigned long long cur = 4;
	unsigned long long shifted = 2;
	while (cur <= to) {
		dp[shifted] = (dp[shifted - 1]  << 1) + last;
		last = cur;
		cur <<= 1;
		++shifted;
	}
	unsigned long long upper = getOnes(dp, shifted, cur, to);
	unsigned long long lower = getOnes(dp, shifted, cur, from);
	cur = 1;
	last = 0;
	while (cur <= from) {
		if (cur & from) ++last;
		cur <<= 1;
	}
	lower -= last;
	printf("%lld\n", upper - lower);
}