#include <iostream>
#include <vector>

struct node {
	int possibility;
	int twos;
};

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	std::vector<node> possibilities{ node{ 0, 0 }, node{1, 0}, node{ 2, 1 } };
	int in;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &in);
		if (in >= possibilities.size()) {
			int j = possibilities.size();
			possibilities.resize(in + 1);
			for (; j <= in; ++j) {
				possibilities[j].twos = j >> 1;
				possibilities[j].possibility = 1 + possibilities[j].twos + (j / 3);
				int cur = j - 3;
				while (cur > 1) {
					possibilities[j].possibility += possibilities[cur].twos;
					cur -= 3;
				}
				if (j == 1) ++possibilities[j].possibility;
			}
		}
		printf("%d\n", possibilities[in].possibility);
	}
}