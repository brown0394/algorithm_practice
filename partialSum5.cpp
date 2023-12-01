#include <iostream>
#include <vector>

int main() {
	int testCases, N;
	scanf_s("%d %d", &N, &testCases);
	std::vector<std::vector<int>> arr(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		scanf_s("%d", &arr[i][0]);
		for (int j = 1; j < N; ++j) {
			scanf_s("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	}
	int startX, startY, X, Y, sum;
	for (int i = 0; i < testCases; ++i) {
		sum = 0;
		scanf_s("%d %d %d %d", &startX, &startY, &X, &Y);
		--Y;
		if (startY == 1) {
			for (int j = startX-1; j < X; ++j) {
				sum += arr[j][Y];
			}
		}
		else {
			for (int j = startX - 1; j < X; ++j) {
				sum += (arr[j][Y] - arr[j][startY - 2]);
			}
		}
		printf("%d\n", sum);
	}
}