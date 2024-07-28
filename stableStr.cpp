#include <iostream>
#include <string>

int main() {
	std::string str;
	int cur = 1;
	while (true) {
		std::cin >> str;
		if (str[0] == '-') break;
		int open = 0;
		int change = 0;
		for (auto it = str.begin(), end = str.end(); it != end; ++it) {
			if (*it == '}') {
				if (open) --open;
				else {
					++change;
					++open;
				}
			}
			else ++open;
		}
		if (open) change += (open >> 1);
		printf("%d. %d\n", cur++, change);
	}
	
}