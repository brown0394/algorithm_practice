#include <iostream>
#include <vector>
#include <list>

int main() {
	int N;
	int elimLen;
	std::vector<int> elims;
	std::list<int> seq;
	while (scanf_s("%d", &N) != EOF) {
		scanf_s("%d", &elimLen);
		if (elims.size() < elimLen) elims.resize(elimLen);
		for (int i = 0; i < elimLen; ++i) {
			scanf_s("%d", &elims[i]);
		}
		for (int i = 1; i <= N; ++i) {
			seq.push_back(i);
		}
		int idx = 0;
		auto it = seq.begin();
		while (N-- > 1) {
			for (int i = 1; i < elims[idx]; ++i) {
				++it;
				if (it == seq.end()) it = seq.begin();
			}
			it = seq.erase(it);
			if (it == seq.end()) it = seq.begin();
			idx = (idx + 1) % elimLen;
		}
		printf("%d\n", seq.front());
		seq.pop_front();
	}
}