#include <iostream>
#include <vector>
#include <bitset>

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &arr[i]);
	}
	std::bitset<100001> isInSet;
	long long sum = 0;
	int right = 1;
	for (int i = 0; i < n; ++i) {
		if (i) isInSet[arr[i - 1]] = false;
		isInSet[arr[i]] = true;
		if (right == i) ++right;
		while (right < n) {
			if (isInSet[arr[right]]) break;
			isInSet[arr[right++]] = true;
		}
		sum += right - i;
	}
	printf("%lld\n", sum);
}