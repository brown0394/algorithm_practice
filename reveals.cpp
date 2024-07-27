#include <iostream>
#include <string>
#include <set>
int main() {
	std::string in;
	std::getline(std::cin, in);
	int people;
	scanf_s("%d", &people);
	std::set<std::string> seen;
	std::string suspects[3]{ "bumin", "cake", "lawyer" };
	bool dongho = false;
	for (int i = 0; i < people; ++i) {
		std::cin >> in;
		auto it = seen.find(in);
		if (it == seen.end()) {
			if (in[0] == 'd' && !dongho && in == "dongho") dongho = true;
			seen.emplace_hint(it, std::move(in), false);
		}
	}
	int peopleSeen;
	scanf_s("%d", &peopleSeen);
	for (int i = 0; i < peopleSeen; ++i) {
		std::cin >> in;
		if (dongho) continue;
		auto it = seen.find(in);
		if (it != seen.end()) {
			seen.erase(it);
		}
	}
	if (dongho) {
		printf("dongho\n");
		return 0;
	}
	for (int i = 0; i < 3; ++i) {
		auto it = seen.find(suspects[i]);
		if (it != seen.end()) {
			printf("%s\n", it->c_str());
			return 0;
		}
	}
	if (seen.empty()) {
		printf("swi\n");
		return 0;
	}
	printf("%s\n", seen.begin()->c_str());
}