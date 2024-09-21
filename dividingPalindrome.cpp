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
	if (start == len) return;
	if (start == 33) 
		int a = 10;
	toursToEndPoint[start] = max;
	for (const int& to : palindromesStartingFrom[start]) {
		if (!toursToEndPoint[to + 1]) checkTourToEnd(to + 1);
		if (toursToEndPoint[to + 1] < toursToEndPoint[start]) toursToEndPoint[start] = toursToEndPoint[to + 1];
	}
	if (!toursToEndPoint[start + 1]) checkTourToEnd(start + 1);
	if (toursToEndPoint[start + 1] < toursToEndPoint[start]) toursToEndPoint[start] = toursToEndPoint[start + 1];
	++toursToEndPoint[start];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> str;
	len = str.size();
	toursToEndPoint.resize(len + 1);
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
	checkTourToEnd(0);
	toursToEndPoint[len - 1] = 1;
	std::cout << toursToEndPoint[0] << '\n';
}