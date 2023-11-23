#include <iostream>
#include <vector>

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<int> arr(N);
	std::vector<int> seqs(N, 1);
	int longestSeq = 0;
	int max;
	for (int i = 0; i < N; ++i) {
		max = 1;
		scanf_s("%d", &arr[i]);
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j] < arr[i] && seqs[j] + 1 > max) {
				max = seqs[j] + 1;
			}
		}
		seqs[i] = max;
		if (max > longestSeq) {
			longestSeq = max;
		}
	}
	printf("%d\n", longestSeq);
}