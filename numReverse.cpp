#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	std::string str;
	for (int i = 0; i < testCases; ++i) {
		std::cin >> str;
		int sum = std::stoi(str);
		std::reverse(str.begin(), str.end());
		sum += std::stoi(str);
		str = std::to_string(sum);
		int begin = 0, rbegin = str.size() - 1;
		bool symmetric = true;
		while (begin < rbegin) {
			if (str[begin] != str[rbegin]) {
				symmetric = false;
				break;
			}
			++begin;
			--rbegin;
		}
		if (symmetric) printf("YES\n");
		else printf("NO\n");
	}
}
