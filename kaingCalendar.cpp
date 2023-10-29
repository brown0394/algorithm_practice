#include <iostream>
#include <vector>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int m, n, x, y;
	int ans = 0;
	int testUntil;
	bool check;
	int* targetMod;
	int* targetRemainder;
	int* mod;
	int* remainder;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d %d %d %d", &m, &n, &x, &y);
		if (x <= m && y <= n && x == y) {
			printf("%d\n", x);
			continue;
		}
		if (m < n) {
			mod = &m;
			remainder = &x;
			targetMod = &n;
			targetRemainder = &y;
		}
		else {
			mod = &n;
			remainder = &y;
			targetMod = &m;
			targetRemainder = &x;
		}
		if (*mod == *remainder) ans = *mod;
		else ans = *mod + *remainder;
		testUntil = m * n;
		if (*targetMod == *targetRemainder) check = true;
		else check = false;
		while (ans <= testUntil) {
			if (check && ans % *targetMod == 0) break;
			if (ans % *targetMod == *targetRemainder) break;
			ans += *mod;
		}
		if (ans > testUntil) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
}