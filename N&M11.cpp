#include <iostream>
#include <vector>
#include <algorithm>

int maxDepth, seqLen;
std::vector<int> sequence;
std::vector<int> inSeq;

void printSeq(int depth) {
	if (depth == maxDepth) {
		printf("%d", sequence[0]);
		for (int i = 1; i < maxDepth; ++i) {
			printf(" %d", sequence[i]);
		}
		printf("\n");
		return;
	}
	bool first = true;
	for (int i = 0; i < seqLen; ++i) {
		if (first) {
			first = false;
			sequence[depth] = inSeq[i];
			printSeq(depth + 1);
		}
		else {
			if (inSeq[i - 1] == inSeq[i]) continue;
			sequence[depth] = inSeq[i];
			printSeq(depth + 1);
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
	for (int i = 0; i < seqLen; ++i) {
		if (i && inSeq[i - 1] == inSeq[i]) continue;
		sequence[0] = inSeq[i];
		printSeq(1);
	}
}