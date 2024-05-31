#include <iostream>
#include <vector>
#include <string>

struct node {
	int num, min;
};

void getMin() {

}

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int test;
	char nums[200];
	std::string mins[101]{"\0", "\0", "1", "7", "4", "2", "6", "8"};
	int last = 7;
	std::string one;
	std::string two;
	one.resize(15);
	two.resize(15);
	std::string *min = &one;
	std::string *cmp = &two;

	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &test);
		int idx = 0;


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