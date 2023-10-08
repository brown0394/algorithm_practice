#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<int> arr(N);
	std::set<int> sequence;
	for (int i = 0; i < N; ++i) {
		scanf_s("%d", &arr[i]);
		sequence.insert(arr[i]);
	}
	int idx = 0;
	std::unordered_map<int, int> idxArr;
	idxArr.reserve(sequence.size());
	for (auto it = sequence.begin(); it != sequence.end(); ++it) {
		idxArr.insert(std::make_pair(*it, idx++));
	}

	printf("%d", idxArr.find(arr[0])->second);
	for (int i = 1; i < arr.size(); ++i) {
		printf(" %d", idxArr.find(arr[i])->second);
	}
	putchar('\n');
}