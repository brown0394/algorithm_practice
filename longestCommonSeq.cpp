#include <iostream>
#include <list>

int main() {
	std::list<int> idxs1[101];
	std::list<int> idxs2[101];
	int size;
	scanf_s("%d", &size);
	for (int i = 0; i < size; ++i) {
		int in;
		scanf_s("%d", &in);
		idxs1[in].push_back(i);
	}
	scanf_s("%d", &size);
	for (int i = 0; i < size; ++i) {
		int in;
		scanf_s("%d", &in);
		idxs2[in].push_back(i);
	}
	int idx1 = -1, idx2 = -1;
	std::list<int> seq;
	for (int i = 100; i; --i) {
		if (!idxs1[i].empty() && !idxs2[i].empty()) {
			auto it2 = idxs2[i].begin();
			for (auto it = idxs1[i].begin(), end = idxs1[i].end(); it != end; ++it) {
				if (*it > idx1) {
					for (auto end = idxs2[i].end(); it2 != end; ++it2) {
						if (*it2 > idx2) {
							seq.push_back(i);
							idx1 = *it;
							idx2 = *it2;
							break;
						}
					}
				}
			}
		}
	}

	printf("%d\n", seq.size());
	for (auto it = seq.begin(), end = seq.end(); it != end; ++it) {
		printf("%d ", *it);
	}
	if (!seq.empty()) printf("\n");
}