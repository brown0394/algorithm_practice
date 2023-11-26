#include <iostream>
#include <vector>

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<std::vector<int>> arr(N, std::vector<int>(3));
	scanf_s("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
	for (int i = 1; i < N; ++i) {
		scanf_s("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		if (arr[i-1][1] < arr[i-1][2]) {
			arr[i][0] += arr[i - 1][1];
		}
		else {
			arr[i][0] += arr[i - 1][2];
		}
		if (arr[i - 1][0] < arr[i - 1][2]) {
			arr[i][1] += arr[i - 1][0];
		}
		else {
			arr[i][1] += arr[i - 1][2];
		}
		if (arr[i - 1][0] < arr[i - 1][1]) {
			arr[i][2] += arr[i - 1][0];
		}
		else {
			arr[i][2] += arr[i - 1][1];
		}
	}
	--N;
	int min = arr[N][0];
	for (int i = 1; i < 3; ++i) {
		if (arr[N][i] < min) min = arr[N][i];
	}
	printf("%d\n", min);
}