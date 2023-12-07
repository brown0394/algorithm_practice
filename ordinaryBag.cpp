#include <iostream>
#include <vector>
#include <algorithm>

bool sortStd(std::vector<int>& one, std::vector<int>& two) {
	return ((float)one[1] / one[0]) > ((float)two[1] / two[0]);
}

int main() {
	int N, weightLimit;
	scanf("%d %d", &N, &weightLimit);
	std::vector<std::vector<int>> arr(N, std::vector<int>(2));
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	std::sort(arr.begin(), arr.end(), sortStd);
	std::vector<std::vector<int>>maxProfitArr(N, std::vector<int>(weightLimit+1, 0));
	std::vector<std::vector<int>> maxProfitCalcArr(N);
	maxProfitCalcArr[N - 1].push_back(weightLimit);
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < maxProfitCalcArr[i].size(); ++j) {
			if (!maxProfitArr[i-1][maxProfitCalcArr[i][j]]) {
				maxProfitCalcArr[i - 1].push_back(maxProfitCalcArr[i][j]);
				maxProfitArr[i - 1][maxProfitCalcArr[i][j]] = 1;
			}
			int wieghtIncludingCur = maxProfitCalcArr[i][j] - arr[i][0];
			if (wieghtIncludingCur >= 0 && !maxProfitArr[i - 1][wieghtIncludingCur]) {
				maxProfitCalcArr[i - 1].push_back(wieghtIncludingCur);
				maxProfitArr[i - 1][wieghtIncludingCur] = 1;
			}
		}
	}
	for (int i = 0; i < maxProfitCalcArr[0].size(); ++i) {
		if (maxProfitCalcArr[0][i] < arr[0][0]) {
			maxProfitArr[0][maxProfitCalcArr[0][i]] = 0;
		}
		else {
			maxProfitArr[0][maxProfitCalcArr[0][i]] = arr[0][1];
		}
	}
	for (int i = 1; i < maxProfitCalcArr.size(); ++i) {
		for (int j = 0; j < maxProfitCalcArr[i].size(); ++j) {
			if (arr[i][0] > maxProfitCalcArr[i][j]) {
				maxProfitArr[i][maxProfitCalcArr[i][j]] = maxProfitArr[i - 1][maxProfitCalcArr[i][j]];
			}
			else {
				if (maxProfitArr[i - 1][maxProfitCalcArr[i][j]] >
					maxProfitArr[i - 1][maxProfitCalcArr[i][j] - arr[i][0]] + arr[i][1]) {
					maxProfitArr[i][maxProfitCalcArr[i][j]] = maxProfitArr[i - 1][maxProfitCalcArr[i][j]];
				}
				else {
					maxProfitArr[i][maxProfitCalcArr[i][j]] = maxProfitArr[i - 1][maxProfitCalcArr[i][j] - arr[i][0]] + arr[i][1];
				}
			}
		}
	}

	printf("%d\n", maxProfitArr[N-1][weightLimit]);
}