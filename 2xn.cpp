#include <iostream>
#include <vector>

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<int> arr(N);
	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i < N; ++i) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	printf("%d\n", arr[N - 1]);
	
	
}