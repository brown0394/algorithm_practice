#include <iostream>
#include <unordered_map>
#include <vector>

struct node {
	int count;
	int firstIdx;
};

int main() {
	int numbers, repeatLimit;
	scanf_s("%d %d", &numbers, &repeatLimit);
	std::unordered_map<int, node> subSet;
	std::vector<int> seq(numbers);

	for (int i = 0; i < numbers; ++i) {
		scanf_s("%d", &seq[i]);
	}
	int longestSubSeq = 0;
	int subSeq = 0;
	for (int i = 0; i < numbers; ++i) {
		auto found = subSet.find(seq[i]);
		if (found == subSet.end()) {
			++subSeq;
			subSet.insert({ seq[i], node{1, i}});
		}
		else {
			if (found->second.count + 1 > repeatLimit) {
				if (longestSubSeq < subSeq) longestSubSeq = subSeq;
				i = found->second.firstIdx;
				if (i + longestSubSeq >= numbers) break;
				subSeq = 0;
				subSet.clear();
			}
			else {
				++found->second.count;
				++subSeq;
			}
		}
	}
	if (longestSubSeq < subSeq) longestSubSeq = subSeq;
	printf("%d\n", longestSubSeq);
}