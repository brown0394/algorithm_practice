#include <iostream>
#include <string>
#include <vector>

void makeStrLengthEqual(std::string& one, std::string& two) {
	for (int i = two.size(); i < one.size(); ++i) {
		two.push_back('-');
	}
}

int main() {
	std::string one, two;
	std::cin >> one >> two;
	if (one.size() > two.size()) {
		makeStrLengthEqual(one, two);
	}
	else if (two.size() > one.size()) {
		makeStrLengthEqual(two, one);
	}
	int len = one.size();
	std::vector<std::vector<int>> matchArr(len + 1, std::vector<int>(len + 1, 0));
	int max = 0;
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= len; ++j) {
			if (one[i-1] == two[j-1]) {
				matchArr[i][j] = matchArr[i - 1][j - 1] + 1;
			}
			else {
				if (matchArr[i - 1][j] >= matchArr[i][j - 1]) {
					matchArr[i][j] = matchArr[i - 1][j];
				}
				else {
					matchArr[i][j] = matchArr[i][j - 1];
				}
			}
		}
	}
	printf("%d\n", matchArr[len][len]);
}