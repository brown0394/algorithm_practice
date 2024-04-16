#include <iostream>
#include <vector>


int main() {
	int testCases;
	scanf_s("%d", &testCases);
	std::vector<int> possibilities{0, 1, 2, 3, 4, 5};
	int in;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &in);
		if (in >= possibilities.size()) {
			int j = possibilities.size();
			possibilities.resize(in + 1);
			for (; j <= in; ++j) {
				possibilities[j] = possibilities[j - 1];
				if ((j - 2) % 2 == 0) ++possibilities[j];
				if ((j - 2) % 3 == 0) ++possibilities[j];
				if ((j - 3) % 2 == 0) ++possibilities[j];
				if ((j - 3) % 3 == 0) ++possibilities[j];
			}
		}
		printf("%d\n", possibilities[in]);
	}
}