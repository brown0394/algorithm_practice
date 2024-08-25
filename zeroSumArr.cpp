#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int len;
	std::cin >> len;
	std::vector<std::vector<int>> arr(4, std::vector<int>(len));
	for (int i = 0; i < len; ++i) {
		std::cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
	}
	int sumsLen = len * len;
	std::vector<int> sumsAB(sumsLen);
	std::vector<int> sumsCD(sumsLen);
	int idx = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			sumsAB[idx] = arr[0][i] + arr[1][j];
			sumsCD[idx++] = arr[2][i] + arr[3][j];
		}
	}
	std::sort(sumsAB.begin(), sumsAB.end());
	std::sort(sumsCD.begin(), sumsCD.end(), std::greater<int>());
	int idx2 = 0;
	idx = 0;
	long long sumZeros = 0;
	while (idx < sumsLen && idx2 < sumsLen) {
		int calc = sumsAB[idx] + sumsCD[idx2];
		if (calc == 0) {
			int last = idx++, last2 = idx2++;
			while (idx < sumsLen && sumsAB[idx] == sumsAB[idx - 1]) ++idx;
			while (idx2 < sumsLen && sumsCD[idx2] == sumsCD[idx2 - 1]) ++idx2;
			sumZeros += ((idx - last) * (idx2 - last2));
		}
		else {
			if (calc < 0) ++idx;
			else ++idx2;
		}
	}
	std::cout << sumZeros;
}