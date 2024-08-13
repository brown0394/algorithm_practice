#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int len1, len2, target;
	std::cin >> target;
	std::cin >> len1;
	std::vector<int> arr1(len1+1, 0);
	std::vector<int> arr1Sums;
	for (int i = 1; i <= len1; ++i) {
		std::cin >> arr1[i];
		arr1[i] += arr1[i - 1];
		for (int j = 0; j < i; ++j) {
			arr1Sums.push_back(arr1[i] - arr1[j]);
		}
	}
	std::cin >> len2;
	std::vector<int> arr2(len2+1);
	std::vector<int> arr2Sums;
	for (int i = 1; i <= len2; ++i) {
		std::cin >> arr2[i];
		arr2[i] += arr2[i - 1];
		for (int j = 0; j < i; ++j) {
			arr2Sums.push_back(arr2[i] - arr2[j]);
		}
	}
	std::sort(arr1Sums.begin(), arr1Sums.end());
	std::sort(arr2Sums.begin(), arr2Sums.end());
	int idx1 = 0;
	len1 = arr1Sums.size();
	int idx2 = arr2Sums.size() - 1;
	long long possibleCombi = 0;
	while (idx1 < len1 && idx2 >= 0) {
		if (arr1Sums[idx1] + arr2Sums[idx2] > target) {
			--idx2;
			continue;
		}
		else if (arr1Sums[idx1] + arr2Sums[idx2] < target) {
			++idx1;
			continue;
		}
		long long ones = 1;
		int cur = arr1Sums[idx1++];
		while (idx1 < len1 && arr1Sums[idx1] == cur) {
			++idx1;
			++ones;
		}
		long long twos = 1;
		cur = arr2Sums[idx2--];
		while (idx2 >= 0 && arr2Sums[idx2] == cur) {
			--idx2;
			++twos;
		}
		possibleCombi += (ones * twos);
	}
	std::cout << possibleCombi << '\n';
}