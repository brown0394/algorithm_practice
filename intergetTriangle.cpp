#include <iostream>
#include <vector>

int main() {
	int N;
	scanf_s("%d", &N);
	int in;
	std::vector<std::vector<int>> arr(N);
	scanf_s("%d", &in);
	arr[0].push_back(in);
	int max = 0;
	for (int i = 1; i < N; ++i) {
		scanf_s("%d", &in);
		arr[i].push_back(in + arr[i-1][0]);
		for (int j = 1; j < i; ++j) {
			scanf_s("%d", &in);
			arr[i].push_back(in);
			if (arr[i - 1][j - 1] > arr[i - 1][j]) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += arr[i - 1][j];
			}
			if (i == N - 1) {
				if (max < arr[i][j]) max = arr[i][j];
			}
		}
		scanf_s("%d", &in);
		arr[i].push_back(in + arr[i - 1][i - 1]);
	}
	if (max < arr[N - 1][N - 1]) max = arr[N - 1][N - 1];
	printf("%d\n", max);
}