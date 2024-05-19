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
	int longestMatch = 0;
	int one = 0, two = 0;
	--n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (strs[i].str[0] == strs[j].str[0]) {
				int idx = 0;
				while (true) {
					if (strs[i].str[idx] == 0 || strs[j].str[idx] == 0) {
						break;
					}
					if (strs[i].str[idx] != strs[j].str[idx]) break;
					++idx;
				}
				if (idx == longestMatch) {
					if (strs[i].idx < strs[one].idx) {
						one = i;
						if (strs[j].str[0] != strs[two].str[0]) {
							two = j;
						}
						else if (strs[two].idx > strs[j].idx) {
							two = j;
						}
					}
					else if (strs[j].idx < strs[one].idx) {
						one = j;
						if (strs[i].str[0] != strs[two].str[0]) {
							two = i;
						}
						else if (strs[two].idx > strs[i].idx) {
							two = i;
						}
					}
					else if (strs[two].str[0] == strs[i].str[0]) {
						if (strs[two].idx > strs[i].idx && i != one) two = i;
						else if (strs[two].idx > strs[j].idx && j != one) two = j;
					}

				}
				else if (idx > longestMatch) {
					if (strs[i].idx < strs[j].idx) {
						one = i;
						two = j;
					}
					else {
						one = j;
						two = i;
					} 
					longestMatch = idx;
				}
			}
		}

	}
	printf("%s\n%s\n", strs[one].str.c_str(), strs[two].str.c_str());
}