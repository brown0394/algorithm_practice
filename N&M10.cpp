#include <iostream>
#include <vector>
#include <algorithm>

int maxDepth, seqLen;
std::vector<int> sequence;
std::vector<int> inSeq;

void printSeq(int depth, int lastIdx) {
	if (depth == maxDepth) {
		printf("%d", sequence[0]);
		for (int i = 1; i < maxDepth; ++i) {
			printf(" %d", sequence[i]);
		}
		printf("\n");
		return;
	}
	int end = seqLen - (maxDepth - depth);
	bool first = true;
	for (++lastIdx; lastIdx <= end; ++lastIdx) {
		if (first) {
			first = false;
			sequence[depth] = inSeq[lastIdx];
			printSeq(depth + 1, lastIdx);
		}
		else {
			if (inSeq[lastIdx - 1] == inSeq[lastIdx]) continue;
			sequence[depth] = inSeq[lastIdx];
			printSeq(depth + 1, lastIdx);
		}
	}
}

int main() {
	scanf_s("%d %d", &seqLen, &maxDepth);
	inSeq.resize(seqLen);
	sequence.resize(maxDepth);
	for (int i = 0; i < seqLen; ++i) {
		scanf_s("%d", &inSeq[i]);
	}
	std::sort(inSeq.begin(), inSeq.end());
	int end = seqLen - maxDepth;
	for (int i = 0; i <= end; ++i) {
		if (i && inSeq[i - 1] == inSeq[i]) continue;
		sequence[0] = inSeq[i];
		printSeq(1, i);
	}
}