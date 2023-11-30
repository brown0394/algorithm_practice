#include <iostream>
#include <vector>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int N;
	std::vector<std::vector<int>> arr(2);
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &N);
		arr[0].resize(N);
		arr[1].resize(N);

		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < N; ++k) {
				scanf_s("%d", &arr[j][k]);
			}
		}
		if (N > 1) {
			arr[0][1] += arr[1][0];
			arr[1][1] += arr[0][0];
			for (int j = 2; j < N; ++j) {
				if (arr[0][j - 1] > arr[0][j - 2]) {
					arr[1][j] += arr[0][j - 1];
				}
				else {
					arr[1][j] += arr[0][j - 2];
				}
				if (arr[1][j - 1] > arr[1][j - 2]) {
					arr[0][j] += arr[1][j - 1];
				}
				else {
					arr[0][j] += arr[1][j - 2];
				}
			}
		}
		if (arr[0][N - 1] > arr[1][N - 1]) {
			printf("%d\n", arr[0][N - 1]);
		}
		else {
			printf("%d\n", arr[1][N - 1]);
		}
	}
}