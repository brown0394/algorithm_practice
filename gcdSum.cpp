#include <iostream>
#include <vector>

int gcd(int one, int two) {
	if (one == two) return one;
	if (one < two) {
		int temp = one;
		one = two;
		two = temp;
	}
	int remainder = one % two;
	while (remainder) {
		one = two;
		two = remainder;
		remainder = one % two;
	}
	return two;
}

int main() {
	int testCases, n;
	scanf_s("%d", &testCases);
	std::vector<int> arr;
	long long sum;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &n);
		arr.resize(n);
		sum = 0;
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &arr[j]);
		}
		for (int j = 0; j < n-1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				sum += gcd(arr[j], arr[k]);
			}
		}
		printf("%lld\n", sum);
	}
}
