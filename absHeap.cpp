#include <iostream>
#include <vector>
#include <algorithm>

bool sortStd(int one, int two) {
	int absOne = one;
	int absTwo = two;
	if (one < 0) absOne = -one;
	if (two < 0) absTwo = -two;
	if (absOne == absTwo) {
		return one > two;
	}
	return absOne > absTwo;
}

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> heap;
	int in;
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &in);
		if (in) {
			heap.push_back(in);
			std::push_heap(heap.begin(), heap.end(), sortStd);
		}
		else {
			if (heap.empty()) printf("0\n");
			else {
				std::pop_heap(heap.begin(), heap.end(), sortStd);
				printf("%d\n", heap.back());
				heap.pop_back();
			}
		}
	}
}