#include <iostream>
#include <set>

int main() {
	std::set<int, std::greater<int>> order;
	int nth;
	scanf_s("%d", &nth);
	int size = nth * nth;
	int in;
	for (int i = 0; i < size; ++i) {
		scanf_s("%d", &in);
		order.insert(in);
		if (order.size() > nth) order.erase(--order.end());
	}
	printf("%d\n", *(--order.end()));
}