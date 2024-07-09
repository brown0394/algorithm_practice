#include <iostream>
#include <vector>

int main() {
	int target;
	const int modVal = 15746;
	scanf_s("%d", &target);
	std::vector<int> dp(target + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= target; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % modVal;
	}
	printf("%d\n", dp[target]);
}