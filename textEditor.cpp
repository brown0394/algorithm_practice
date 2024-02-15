#include <iostream>
#include <cstring>
#include <list>

int main() {
	std::list<char> text;
	char op, letter;
	while(true) {
		scanf_s("%c", &letter);
		if (letter == '\n') break;
		text.push_back(letter);
	}
	int operations;
	scanf_s("%d", &operations);
	std::list<char>::iterator it = text.end();
	for (int i = 0; i < operations; ++i) {
		getchar();
		scanf_s("%c", &op);
		switch (op) {
		case 'L': { if (it != text.begin()) --it; break; }
		case 'D': { if (it != text.end()) ++it; break; }
		case 'B': { 
			if (it != text.begin()) {
				--it;
				it = text.erase(it);
			}
			break; 
		}
		case 'P': {
			scanf_s(" %c", &letter);
			it = text.insert(it, letter);
			++it;
			break;
		}
		}
	}
	it = text.begin();
	for (; it != text.end(); ++it) printf("%c", *it);
	printf("\n");
}
