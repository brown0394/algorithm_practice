#include <iostream>
#include <vector>
#include <string>

struct node {
	int num, min;
};
std::string mins[101]{ "\0", "\0", "1", "7", "4", "2", "6", "8", "10"};
std::string one;
std::string two;

void join(std::string& one, char two, std::string* ret) {
	if (one[0] > two) {
		*ret = std::move(two + one);
		return;
	}
	if (two == '6') two = '0';
	for (int i = 1, end = one.size(); i < end; ++i) {
		if (one[i] > two) {
			*ret = std::move(one.substr(0, i) + two + one.substr(i));
			return;
		}
	}
	*ret = std::move(one + two);
}

std::string&& getMin(int idx) {
	std::string* min = &one;
	std::string* cmp = &two;
	join(mins[idx - 7], mins[7][0], min);
	int cur = (idx - 1) / 7;
	for (int i = 6; i >= 2; --i) {
		if ((idx - i - 1) / 7 == cur) break;
		join(mins[idx - i], mins[i][0], cmp);
		if (*cmp < *min) {
			std::string* tmp = cmp;
			cmp = min;
			min = tmp;
		}
	}
	return std::move(*min);
}

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int test;

	one.resize(15);
	two.resize(15);

	int last = 8;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &test);
		int idx = 0;
		for (int i = last + 1; i <= test; ++i) {
			mins[i] = getMin(i);
		}
		printf("%s ", mins[test].c_str());
		if (test % 2) {
			putchar('7');
			int ones = ((test - 1) >> 1) - 1;
			for (int j = 0; j < ones; ++j) putchar('1');
			putchar('\n');
		}
		else {
			int ones = test >> 1;
			for (int j = 0; j < ones; ++j) putchar('1');
			putchar('\n');
		}
	}
}