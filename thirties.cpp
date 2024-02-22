#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string str;
	std::cin >> str;
	std::sort(str.rbegin(), str.rend());
	if (str.back() == '0') {
		int num = 0;
		for (auto it = str.begin(); it != str.end(); ++it) {
			num = (num + (*it + '0')) % 3;
			num *= 10;
		}
		if (!num) {
			printf("%s\n", str.c_str());
			return 0;
		}
	}
	printf("-1\n");
}
