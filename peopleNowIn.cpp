#include <iostream>
#include <set>
#include <string>



int main() {
	std::set<std::string> log;
	int n;
	scanf_s("%d", &n);
	std::string name;
	std::string op;
	for (int i = 0; i < n; ++i) {
		std::cin >> name >> op;
		if (op[0] == 'e') {
			log.insert(name);
		}
		else {
			log.erase(name);
		}
	}
	for (auto it = log.rbegin(); it != log.rend(); ++it) {
		printf("%s\n", it->c_str());
	}
}
