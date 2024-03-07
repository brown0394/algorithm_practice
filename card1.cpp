#include <iostream>
#include <deque>

int main() {
	int numOfCards;
	std::deque<short int> dq;
	scanf_s("%d", &numOfCards);
	printf("1");
	for (int i = 2; i <= numOfCards; ++i) {
		dq.push_back(i);
	}
	while (!dq.empty()) {
		dq.push_back(dq.front());
		dq.pop_front();
		printf(" %d", dq.front());
		dq.pop_front();
	}
	printf("\n");
}
