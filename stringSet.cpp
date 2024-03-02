#include <iostream>
#include <set>
#include <string>

int main() {
	int sets, checks;
	std::set<std::string> strs;
	scanf_s("%d %d", &sets, &checks);
	char input[501];
	getchar();
	for (int i = 0; i < sets; ++i) {
		scanf_s("%s", input, 501);
		strs.insert(input);
	}
	int inSet = 0;
	for (int i = 0; i < checks; ++i) {
		scanf_s("%s", input, 501);
		auto found = strs.find(input);
		if (found != strs.end()) ++inSet;
	}
	printf("%d\n", inSet);
}
