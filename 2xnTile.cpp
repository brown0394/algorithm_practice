#include <iostream>
#include <vector>

int main() {
	int N, testCases;
	std::vector<int> arr(2, 1);
	arr[1] = 3;
	scanf_s("%d", &N);
	for (int i = 2; i < N; ++i) {
		arr.push_back((arr[i - 1] + (arr[i-2] << 1)) %10007);
	}
	printf("%d\n", arr[N - 1]);
}