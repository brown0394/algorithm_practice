#include <iostream>
#include <vector>

#define MOD 1'000'000'000

int main() {
	int target, elems;
	scanf_s("%d %d", &target, &elems);
	std::vector<std::vector<int>> rec(elems + 1, std::vector<int>(target + 1, 1));
	for (int i = 2; i <= elems; ++i) {
		for (int j = 1; j <= target; ++j) {
			rec[i][j] = (rec[i][j - 1] + rec[i - 1][j]) % MOD;
		}
	}
	printf("%d\n", rec[elems][target]);
}
