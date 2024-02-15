#include <iostream>
#include <vector>


int size;
std::vector<std::vector<int>> record;

void zigZag(int smaller, int bigger) {
	int i = smaller;
	int j = bigger - 1;
	record[smaller][bigger] = 0;
	while (j >= 0) {
		if (record[j][i] == -1) zigZag(j, i);
		record[smaller][bigger] = (record[smaller][bigger] + record[j][i]) % 1000'000;
		++i;
		--j;
	}
}

int main() {
	scanf_s("%d", &size);
	record.resize(size + 1, std::vector<int>(size + 1, -1));
	for (int i = 1; i <= size; ++i) {
		record[i][0] = 0;
	}
	record[0][0] = 1;
	record[0][1] = 1;
	int ans = 0;
	int i = 0;
	int j = size - 1;
	if (j == 0 && i == 0) {
		printf("1\n");
		return 0;
	}
	while (j >= 0) {
		if (record[j][i] == -1) zigZag(j, i);
		ans = (ans + record[j][i]) % 1000'000;
		if (record[i][j] == -1) zigZag(i, j);
		ans = (ans + record[i][j]) % 1000'000;
		++i;
		--j;
	}
	printf("%d\n", ans);
}
