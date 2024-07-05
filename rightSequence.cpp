#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int size;
	scanf_s("%d", &size);
	std::vector<int> seq(size);
	for (int i = 0; i < size; ++i) {
		scanf_s("%d", &seq[i]);
	}
	std::sort(seq.begin(), seq.end());
	int minElemsToAdd = 4;
	
	int start = seq[0];
	for (int i = 0; i < size; ++i) {
		int members = 1;
		for (int j = i + 1, till = i + 4; j < size && j <= till; ++j) {
			if (seq[j] - seq[i] > 4) {
				break;
			}
			++members;
		}
		if (5 - members < minElemsToAdd) minElemsToAdd = 5 - members;
	}
	printf("%d\n", minElemsToAdd);
}