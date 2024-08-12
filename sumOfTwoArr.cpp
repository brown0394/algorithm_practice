#include <iostream>
#include <vector>
#include <map>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int len1, len2, target;
	std::cin >> target;
	std::cin >> len1;
	std::vector<int> arr1(len1+1);
	for (int i = 1; i <= len1; ++i) {
		std::cin >> arr1[i];
		arr1[i] += arr1[i - 1];
	}
	std::cin >> len2;
	std::vector<int> arr2(len2+1);
	std::map<int, int> arr2Sums;
	for (int i = 1; i <= len2; ++i) {
		std::cin >> arr2[i];
		arr2[i] += arr2[i - 1];
		for (int j = i - 1; j >= 0; --j) {
			int cur = arr2[i] - arr2[j];
			if (cur > target) break;
			auto found = arr2Sums.find(cur);
			if (found == arr2Sums.end()) arr2Sums.insert({ cur, 1 });
			else ++found->second;
		}
	}
	int start1 = 0, end1 = 1;
	int possibleCombi = 0;
	for (int i = 1; i <= len1; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr1[i] - arr1[j] > target) break;
			int toFind = target - (arr1[i] - arr1[j]);
			auto found = arr2Sums.find(toFind);
			if (found != arr2Sums.end()) possibleCombi += found->second;
		}
	}
	std::cout << possibleCombi << '\n';
}