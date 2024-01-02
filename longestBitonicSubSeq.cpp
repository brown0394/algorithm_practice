#include <iostream>
#include <vector>

struct node {
	int num;
	int incCount;
	int incrFrom;
	int decCount;
	int decrFrom;
};

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<int> arr(N);
	std::vector<int> incrSeqs(N, 1);
	std::vector<int> decrSeqs(N, 1);
	int longestSeq = 0;
	int max;
	for (int i = 0; i < N; ++i) {
		max = 1;
		scanf_s("%d", &arr[i]);
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j] < arr[i] && incrSeqs[j] + 1 > max) {
				max = incrSeqs[j] + 1;
			}
		}
		incrSeqs[i] = max;
	}
	for (int i = N - 1; i >= 0; --i) {
		max = 1;
		for (int j = i + 1; j < N; ++j) {
			if (arr[j] < arr[i] && decrSeqs[j] + 1 > max) {
				max = decrSeqs[j] + 1;
			}
		}
		decrSeqs[i] = max;
		max = decrSeqs[i] + incrSeqs[i];
		if (max > longestSeq) longestSeq = max;
	}
	printf("%d\n", longestSeq - 1);
}