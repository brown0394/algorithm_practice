#include <iostream>
#include <vector>
#include <algorithm>


void getCommands() {
	std::vector<int> maxQ;
	std::vector<int> minQ;
	int commands;
	scanf_s("%d", &commands);
	char command;
	int num;
	for (int i = 0; i < commands; ++i) {
		getchar();
		scanf_s("%c %d", &command, 1, &num);
		switch (command) {
		case 'I': {
			minQ.push_back(num);
			maxQ.push_back(num);
			std::push_heap(maxQ.begin(), maxQ.end(), std::less<int>{});
			std::push_heap(minQ.begin(), minQ.end(), std::greater<int>{});
			break;
		}
		case 'D': {
			if (maxQ.empty()) break;
			if (num > 0) {
				std::pop_heap(maxQ.begin(), maxQ.end(), std::less<int>{});
				int toFind = maxQ.back();
				maxQ.pop_back();
				int len = minQ.size()-1;
				for (int i = len; i >= 0; --i) {
					if (minQ[i] == toFind) {
						if (i < len) {
							minQ[i] = minQ[len];
							minQ.pop_back();
							std::make_heap(minQ.begin(), minQ.end(), std::greater<int>{});
						}
						else {
							minQ.pop_back();
						}
						break;
					}
				}
			}
			else {
				std::pop_heap(minQ.begin(), minQ.end(), std::greater<int>{});
				int toFind = minQ.back();
				minQ.pop_back();
				int len = maxQ.size() - 1;
				for (int i = len; i >= 0; --i) {
					if (maxQ[i] == toFind) {
						if (i < len) {
							maxQ[i] = maxQ[len];
							maxQ.pop_back();
							std::make_heap(maxQ.begin(), maxQ.end(), std::less<int>{});
						}
						else {
							maxQ.pop_back();
						}
						break;
					}
				}
			}
			break;
		}
		}
	}
	if (maxQ.empty()) {
		printf("EMPTY\n");
	}
	else {
		printf("%d %d\n", maxQ[0], minQ[0]);
	}
}
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		getCommands();
	}
}