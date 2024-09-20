#include <iostream>
#include <vector>
#include <string>
#include <bitset>

std::vector<int> toursToEndPoint;
std::vector<std::vector<int>> palindromesStartingFrom;
const int max = 2505;
std::string str;
int len;
std::vector<std::bitset<max>> isSubPalindrome;
void checkPalindrome(int start, int end) {
	while (end < len && start >= 0 && str[start] == str[end]) {
		palindromesStartingFrom[start].push_back(end);
		isSubPalindrome[start--][end++] = true;
	}
}

void checkTourToEnd(int start) {
	toursToEndPoint[start] = max;
	for (const int& to : palindromesStartingFrom[start]) {
		if (!toursToEndPoint[to]) checkTourToEnd(to);
		if (toursToEndPoint[to] < toursToEndPoint[start]) toursToEndPoint[start] = toursToEndPoint[to];
	}
	if (!toursToEndPoint[start + 1]) checkTourToEnd(start + 1);
	if (toursToEndPoint[start + 1] < toursToEndPoint[start]) toursToEndPoint[start] = toursToEndPoint[start + 1] + 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> str;
	len = str.size();
	toursToEndPoint.resize(len);
	isSubPalindrome.resize(len);
	palindromesStartingFrom.resize(len);
	for (int i = 0; i < len; ++i) {
		isSubPalindrome[i][i] = true;
		if (i + 1 < len) {
			checkPalindrome(i, i + 1);
			if (i) {
				checkPalindrome(i - 1, i + 1);
			}
		}
	}
	toursToEndPoint[len - 1] = 1;
	checkTourToEnd(0);
	std::cout << toursToEndPoint[0] << '\n';
}