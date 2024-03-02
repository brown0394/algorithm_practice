#include <iostream>
#include <vector>

std::vector<int> arr;
int size, target;

int partialSum(int i, int sum) {
	int numOfSeqs = 0;
	if (sum == target) ++numOfSeqs;
	for (; i < size; ++i) {
		numOfSeqs += partialSum(i + 1, sum + arr[i]);
	}
	return numOfSeqs;
}

int main() {
	scanf_s("%d %d", &size, &target);
	arr.resize(size);
	for (int i = 0; i < size; ++i) {
		scanf_s("%d", &arr[i]);
	}
	int seqs = 0;
	for (int i = 0; i < size; ++i) {
		seqs += partialSum(i + 1, arr[i]);
	}
	printf("%d\n", seqs);
}
