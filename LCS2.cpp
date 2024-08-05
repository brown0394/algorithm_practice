#include <iostream>
#include <vector>
#include <string>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::string str1, str2;
	std::cin >> str1 >> str2;
	int len1 = str1.size(), len2 = str2.size();
	std::vector<std::vector<int>> letterCount(len1 + 1, std::vector<int>(len2 + 1));
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (str1[i-1] == str2[j-1]) {
				letterCount[i][j] = letterCount[i - 1][j - 1] + 1;
			}
			else {
				if (i) letterCount[i][j] = letterCount[i - 1][j];
				if (j && letterCount[i][j - 1] > letterCount[i][j]) letterCount[i][j] = letterCount[i][j - 1];
			}
			std::cout << letterCount[i][j];
		}
		std::cout << std::endl;
	}
	std::string result;
	result.reserve(len1 + 1);
	result.push_back('\n');
	int subLen = letterCount[len1][len2];
	int cur = subLen;
	while (len1 && len2) {
		if (letterCount[len1][len2] == letterCount[len1 - 1][len2]) --len1;
		else if (letterCount[len1][len2] == letterCount[len1][len2 - 1]) --len2;
		else {
			--len1;
			--len2;
			result.push_back(str1[len1]);
		}
	}
	std::cout << subLen << '\n';
	if (subLen) {
		for (auto it = result.rbegin(), end = result.rend(); it != end; ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;
	}
}