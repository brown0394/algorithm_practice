#include <iostream>
#include <list>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	std::list<int> students;
	for (int i = 0; i < testCases; ++i) {
		int caseNo, num;
		int steps = 0;
		scanf_s("%d", &caseNo);
		int len = 0;
		for (int j = 0; j < 20; ++j) {
			scanf_s("%d", &num);
			int loc = 0;
			for (auto it = students.begin(); it != students.end(); ++it) {
				if (num < *it) {
					students.insert(it, num);
					steps += (len - loc);
					break;
				}
				++loc;
			}
			if (len == students.size()) students.push_back(num);
			++len;
		}
		printf("%d %d\n", caseNo, steps);
		students.clear();
	}
}
