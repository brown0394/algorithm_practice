#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int size;
	scanf_s("%d", &size);
	std::vector<int> seq(size);
	std::vector<int> sums(size, 0);
	for (int i = 0; i < size; ++i) {
		scanf_s("%d", &seq[i]);
		sums[i] = seq[i];
	}
	int max = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (seq[j] > seq[i] && sums[j] < seq[j] + sums[i]) {
				sums[j] = seq[j] + sums[i];
			}
		}
		if (sums[i] > max) max = sums[i];
	}
	printf("%d\n", max);
}