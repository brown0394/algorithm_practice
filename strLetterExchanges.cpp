#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string str;
	std::cin >> str;
	int As = std::count(str.begin(), str.end(), 'a');
	int aCount = 0;
	for (int i = 0; i < As; ++i) {
		if (str[i] == 'a') ++aCount;
	}
	int min = As - aCount;
	for (int i = 1, size = str.size(); i < size; ++i) {
		if (str[i - 1] == 'a') --aCount;
		if (str[(i + As - 1) % size] == 'a') ++aCount;
		if ((As - aCount) < min) min = As - aCount;
	}
	printf("%d\n", min);
}