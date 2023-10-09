#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	scanf_s("%d", &N);
	int in;
	std::vector<int> heap;
	for (int i = 0; i < N; ++i) {
		scanf_s("%d", &in);
		if (in) {
			heap.push_back(in);
			std::push_heap(heap.begin(), heap.end(), std::greater<int>());
		}
		else {
			if (!heap.empty()) {
				std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
				printf("%d\n", heap.back());
				heap.pop_back();
			}
			else {
				printf("0\n");
			}
		}
	}

}