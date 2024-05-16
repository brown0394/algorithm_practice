#include <iostream>
#include <vector>

int maxDepth, seqLen;
std::vector<int> sequence;

void printSeq(int depth) {
	if (depth == maxDepth) {
		printf("%d", sequence[0]);
		for (int i = 1; i < maxDepth; ++i) {
			printf(" %d", sequence[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= seqLen; ++i) {
		sequence[depth] = i;
		printSeq(depth + 1);
	}
}

int main() {
	scanf_s("%d %d", &seqLen, &maxDepth);
	sequence.resize(seqLen);
	for (int i = 1; i <= seqLen; ++i) {
		sequence[0] = i;
		printSeq(1);
	}
}