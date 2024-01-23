#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &arr[i]);
	}
	std::sort(arr.begin(), arr.end(), std::greater<int>());
	int ans = -1;
	for (int i = 2; i < n; ++i) {
		if (arr[i - 2] < arr[i - 1] + arr[i]) {
			ans = arr[i - 2] + arr[i - 1] + arr[i];
			break;
		}
	}
	printf("%d\n", ans);
}
