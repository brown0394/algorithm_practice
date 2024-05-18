#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct node {
	std::string str;
	int idx;
	bool operator < (const node& other) {
		return str < other.str;
	}
};

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<node> strs(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> strs[i].str;
		strs[i].idx = i;
	}
	std::sort(strs.begin(), strs.end());
	int longestMatch = -1;
	--n;
	int one, two;
	for (int i = 0; i < n; ++i) {
		if (strs[i].str[0] == strs[i + 1].str[0]) {
			int idx = 0;
			int cmp = i + 1;
			while (true) {
				if (strs[i].str[idx] == 0 || strs[cmp].str[idx] == 0) {
					break;
				}
				if (strs[i].str[idx] != strs[cmp].str[idx]) break;
				++idx;
			}
			if (idx == longestMatch) {
				if (strs[i].idx < one || strs[i + 1].idx < one) {
					if (strs[i].idx < strs[i + 1].idx) {
						one = strs[i].idx;
						two = strs[i + 1].idx;
					}
					else {
						two = strs[i].idx;
						one = strs[i + 1].idx;
					}
				}
			}
			else if (idx > longestMatch) {
				longestMatch = idx;
				if (strs[i].idx < strs[i + 1].idx) {
					one = strs[i].idx;
					two = strs[i + 1].idx;
				}
				else {
					two = strs[i].idx;
					one = strs[i + 1].idx;
				}
			}
		}
	}
	printf("%s\n%s\n", strs[one].str.c_str(), strs[two].str.c_str());
}