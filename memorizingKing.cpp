#include <iostream>
#include <set>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	std::set<int> notepad;
	for (int i = 0; i < testCases; ++i) {
		int numbers;
		scanf_s("%d", &numbers);
		int in;
		for (int j = 0; j < numbers; ++j) {
			scanf_s("%d", &in);
			notepad.insert(in);
		}
		scanf_s("%d", &numbers);
		for (int j = 0; j < numbers; ++j) {
			scanf_s("%d", &in);
			auto found = notepad.find(in);
			if (found == notepad.end()) printf("0\n");
			else printf("1\n");
		}
		notepad.clear();
	}
	
}
