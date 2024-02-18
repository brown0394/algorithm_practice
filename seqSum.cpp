#include <iostream>
#include <vector>

int main() {
	int num;
	scanf_s("%d", &num);
	std::vector<int> seq(num);
	scanf_s("%d", &seq[0]);
	int max = seq[0];
	for (int i = 1; i < num; ++i) {
		scanf_s("%d", &seq[i]);
		if (seq[i - 1] > 0) seq[i] += seq[i - 1];
		if (seq[i] > max) max = seq[i];
	}
	printf("%d\n", max);
}
