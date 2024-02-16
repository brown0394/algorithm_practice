#include <iostream>
#include <vector>

#define MOD 1'000'000'009

int main() {
	int cases;
	scanf_s("%d\n", &cases);
	std::vector<int[3]> combSums(100'000);
	combSums[0][0] = 1;
	combSums[1][1] = 1;
	for (int i = 0; i < 3; ++i) combSums[2][i] = 1;
	int in;
	int done = 2;
	long long sum;
	for (int i = 0; i < cases; ++i) {
		scanf_s("%d", &in);
		--in;
		while (in > done) {
			++done;
			for (int j = 0; j < 3; ++j) {
				sum = combSums[done - (j + 1)][(j + 1) % 3] + combSums[done - (j + 1)][(j + 2) % 3];
				combSums[done][j] = sum % MOD;
			}
		}
		sum = combSums[in][0] + combSums[in][1];
		sum += combSums[in][2];
		printf("%lld\n", sum % MOD);
	}
}
